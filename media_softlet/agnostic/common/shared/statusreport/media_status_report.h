/*
* Copyright (c) 2018-2021, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/
//!
//! \file     media_status_report.h
//! \brief    Defines the class for media status report
//! \details  
//!
#ifndef __MEDIA_STATUS_REPORT_H__
#define __MEDIA_STATUS_REPORT_H__

#include "mos_os_specific.h"
#include "media_status_report_observer.h"

#define STATUS_REPORT_GLOBAL_COUNT 0

enum CsEngineIdDef
{
    // Instance ID
    csInstanceIdVdbox0 = 0,
    csInstanceIdVdbox1 = 1,
    csInstanceIdVdbox2 = 2,
    csInstanceIdVdbox3 = 3,
    csInstanceIdVdbox4 = 4,
    csInstanceIdVdbox5 = 5,
    csInstanceIdVdbox6 = 6,
    csInstanceIdVdbox7 = 7,
    csInstanceIdMax,
    // Class ID
    classIdVideoEngine = 1,
};

union CsEngineId
{
    struct
    {
        uint32_t       classId            : 3;    //[0...4]
        uint32_t       reservedFiled1     : 1;    //[0]
        uint32_t       instanceId         : 6;    //[0...7]
        uint32_t       reservedField2     : 22;   //[0]
    } fields;
    uint32_t            value;
};

class MediaStatusReport
{
public:

    typedef enum
    {
        querySkipped = 0x00,
        queryStart   = 0x01,
        queryEnd     = 0xFF
    } ExecutingStatus;

    struct StatusBufAddr
    {
        MOS_RESOURCE *osResource;
        uint32_t     offset;
        uint32_t     bufSize;
    };

    //!
    //! \brief  Constructor
    //!
    MediaStatusReport(PMOS_INTERFACE osInterface);
    virtual ~MediaStatusReport() {};

    //!
    //! \brief  Create resources for status report and do initialization
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS Create() = 0;
    //!
    //! \brief  Initialize the status in report for each item
    //! 
    //! \details Called per frame for normal usages.
    //!          It can be called per tilerow if needed.
    //!
    //! \param  [in] inputPar
    //!         Pointer to parameters pass to status report.
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS Init(void *inputPar) = 0;
    //!
    //! \brief  Reset Status
    //! 
    //! \details Called per frame for normal usages.
    //!          It can be called per tilerow if needed.
    //!
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS Reset() = 0;
    //!
    //! \brief  The entry to get status report.
    //! \param  [in] numStatus
    //!         The requested number of status reports
    //! \param  [out] status
    //!         The point to encode status
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    //!
    MOS_STATUS GetReport(uint16_t numStatus, void *status);
    //!
    //! \brief  Get address of status report.
    //! \param  [in] statusReportType
    //!         status report item type
    //! \param  [out] pOsResource
    //!         The point to PMOS_RESOURCE of each item
    //! \param  [out] offset
    //!         Offset of each item
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    //!
    MOS_STATUS GetAddress(uint32_t statusReportType, PMOS_RESOURCE &osResource, uint32_t &offset);
    //!
    //! \brief  Get submitted count of status report.
    //! \return m_submittedCount
    //!
    uint32_t GetSubmittedCount() const { return m_submittedCount; }

#if (_DEBUG || _RELEASE_INTERNAL)
    //!
    //! \brief  Is Vdbox physical id reporting enabled
    //! \return m_enableVdboxIdReport
    //!
    uint32_t IsVdboxIdReportEnabled()
    { 
        return m_enableVdboxIdReport;
    }

    //!
    //! \brief  Parse Vdbox Ids from CsEngineId status buffer
    //! \return void
    //!
    void ParseVdboxIdsFromBuf(const uint32_t *csEngineIdRegBuf);

    //!
    //! \brief  Report Used Vdbox Ids
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS ReportUsedVdboxIds();
#endif
    //!
    //! \brief  Get completed count of status report.
    //! \return The content of m_completedCount
    //!
    uint32_t GetCompletedCount() const 
    {
        if (m_completedCount == nullptr)
        {
            return 0;
        } 
        return (*m_completedCount); 
    }

    //!
    //! \brief  Get reported count of status report.
    //! \return m_reportedCount
    //!
    uint32_t GetReportedCount() const { return m_reportedCount; }

    uint32_t GetIndex(uint32_t count) { return CounterToIndex(count); }
    //!
    //! \brief  Regist observer of complete event.
    //! \param  [in] observer
    //!         The point to StatusReportObserver who will observe the complete event
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS RegistObserver(MediaStatusReportObserver *observer);

    //!
    //! \brief  Unregist observer of complete event.
    //! \param  [in] observer
    //!         The point to StatusReportObserver
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS UnregistObserver(MediaStatusReportObserver *observer);

protected:
    //!
    //! \brief  Collect the status report information into report buffer.
    //! \param  [in] report
    //!         The report buffer address provided by DDI.
    //! \param  [in] index
    //!         The index of current requesting report.
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS ParseStatus(void *report, uint32_t index) = 0;

    //!
    //! \brief  Set unavailable status report information into report buffer.
    //! \param  [in] report
    //!         The report buffer address provided by DDI.
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    virtual MOS_STATUS SetStatus(void *report, uint32_t index, bool outOfRange = false) = 0;
    //!
    //! \brief  Notify observers that the frame has been completed.
    //! \param  [in] statusBuffer
    //!         The point to status buffer
    //! \param  [in,out] statusReport
    //!         The point to status report
    //! \return MOS_STATUS
    //!         MOS_STATUS_SUCCESS if success, else fail reason
    //!
    MOS_STATUS NotifyObservers(void *mfxStatus, void *rcsStatus, void *statusReport);

    void Lock(){m_lock.lock();};
    void UnLock(){m_lock.unlock();};

    inline uint32_t CounterToIndex(uint32_t counter)
    {
        return counter & (m_statusNum - 1);
    }

    static const uint32_t m_statusNum        = 512;

    PMOS_RESOURCE    m_completedCountBuf     = nullptr;
    uint32_t         *m_completedCount       = nullptr;
    uint32_t         m_submittedCount        = 0;
    uint32_t         m_reportedCount         = 0;
    uint32_t         m_sizeOfReport          = 0;

    StatusBufAddr    *m_statusBufAddr        = nullptr;

#if (_DEBUG || _RELEASE_INTERNAL)
    bool             m_enableVdboxIdReport   = false;
    uint32_t         m_usedVdboxIds          = 0;      //!< Used Vdbox physical engine id. Default 0 is not used. Each Hex symbol represents one VDBOX, e.g. bits[3:0] means VD0, bits[7:4] means VD1.
#endif
    MediaUserSettingSharedPtr                 m_userSettingPtr  = nullptr;  //!< user setting instance
    std::recursive_mutex                      m_lock;
    std::vector<MediaStatusReportObserver *>  m_completeObservers;
MEDIA_CLASS_DEFINE_END(MediaStatusReport)
};

#endif // !__MEDIA_STATUS_REPORT_H__
