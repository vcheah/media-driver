﻿/*===================== begin_copyright_notice ==================================

* Copyright (c) 2024, Intel Corporation
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

======================= end_copyright_notice ==================================*/
//!
//! \file     mhw_mi_hwcmd_xe2_lpm_base_next.h
//! \brief    Auto-generated constructors for MHW and states.
//! \details  This file may not be included outside of XE2_LPM_BASE as other components
//!           should use MHW interface to interact with MHW commands and states.
//!
#ifndef __MHW_MI_HWCMD_XE2_LPM_BASE_NEXT_H__
#define __MHW_MI_HWCMD_XE2_LPM_BASE_NEXT_H__

#include "mhw_hwcmd.h"
#pragma once
#pragma pack(1)

namespace mhw
{
namespace mi
{
namespace xe2_lpm_base_next
{
    struct Cmd
    {
    public:
    // Internal Macros
    #define __CODEGEN_MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
    #define __CODEGEN_BITFIELD(l, h) (h) - (l) + 1
    #define __CODEGEN_OP_LENGTH_BIAS 2
    #define __CODEGEN_OP_LENGTH(x) (uint32_t)((__CODEGEN_MAX(x, __CODEGEN_OP_LENGTH_BIAS)) - __CODEGEN_OP_LENGTH_BIAS)

        static uint32_t GetOpLength(uint32_t uiLength)
        {
            return __CODEGEN_OP_LENGTH(uiLength);
        }

            //!
        //! \brief MI_BATCH_BUFFER_END
        //! \details
        //!     The MI_BATCH_BUFFER_END command is used to terminate the execution of
        //!     commands stored in a batch buffer initiated using a
        //!     MI_BATCH_BUFFER_START command.
        //!
        //!     SW must ensure it buffers the size of the command buffer beyond this
        //!     command. The command buffer for the command streamer is 0.5KB.
        //!
        //!     SW must ensure it buffers the size of the command buffer beyond this
        //!     command. The command buffer for the command streamer is 1 KB.
        //!
        struct MI_BATCH_BUFFER_END_CMD
        {
            union
            {
                struct
                {
                    uint32_t EndContext : __CODEGEN_BITFIELD(0, 0);         //!< End Context
                    uint32_t Reserved1 : __CODEGEN_BITFIELD(1, 14);         //!< Reserved
                    uint32_t PredicateEnable : __CODEGEN_BITFIELD(15, 15);  //!< Predicate Enable
                    uint32_t Reserved16 : __CODEGEN_BITFIELD(16, 22);       //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;

            //! \name Local enumerations

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIBATCHBUFFEREND = 10,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_BATCH_BUFFER_END_CMD()
            {
                DW0.Value = 0x05000000;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIBATCHBUFFEREND;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;
            }

            static const size_t dwSize   = 1;
            static const size_t byteSize = 4;
        };

        //!
        //! \brief MI_NOOP
        //! \details
        //!     The MI_NOOP command basically performs a "no operation" in the command
        //!     stream and is typically used to pad the command stream (e.g., in order
        //!     to pad out a batch buffer to a QWord boundary). However, there is one
        //!     minor (optional) function this command can perform - a 22-bit value can
        //!     be loaded into the MI NOPID register. This provides a general-purpose
        //!     command stream tagging ("breadcrumb") mechanism (e.g., to provide
        //!     sequencing information for a subsequent breakpoint interrupt).
        //!
        struct MI_NOOP_CMD
        {
            union
            {
                struct
                {
                    uint32_t IdentificationNumber : __CODEGEN_BITFIELD(0, 21);                      //!< Identification Number
                    uint32_t IdentificationNumberRegisterWriteEnable : __CODEGEN_BITFIELD(22, 22);  //!< IDENTIFICATION_NUMBER_REGISTER_WRITE_ENABLE
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                          //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                              //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;

            //! \name Local enumerations

            //! \brief IDENTIFICATION_NUMBER_REGISTER_WRITE_ENABLE
            //! \details
            //!     This field enables the value in the Identification Number field to be
            //!     written into the MI NOPID register. If disabled, that register is
            //!     unmodified - making this command an effective "no operation" function.
            enum IDENTIFICATION_NUMBER_REGISTER_WRITE_ENABLE
            {
                IDENTIFICATION_NUMBER_REGISTER_WRITE_ENABLE_UNNAMED0 = 0,  //!< Do not write the NOP_ID register
                IDENTIFICATION_NUMBER_REGISTER_WRITE_ENABLE_UNNAMED1 = 1,  //!< Write th NOP_ID Register
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MINOOP = 0,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_NOOP_CMD()
            {
                DW0.Value = 0x00000000;
                //DW0.IdentificationNumberRegisterWriteEnable      = IDENTIFICATION_NUMBER_REGISTER_WRITE_ENABLE_DISABLE;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MINOOP;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;
            }

            static const size_t dwSize   = 1;
            static const size_t byteSize = 4;
        };

        //!
        //! \brief MI_ARB_CHECK
        //! \details
        //!     This command allows software to enable or disable pre-fetch mechanism
        //!     for command buffers in hardware.
        //!
        //!     The command allows software to add preemption points in the ring buffer.
        //!     The command streamer will preempt in the case arbitration is enabled,
        //!     there is a pending execution list and this command is currently being
        //!     parsed.
        //!
        //!     MI_ARB_CHK command can be programmed in a ring buffer or batch buffer.
        //!
        //!     MI_ARB_CHK command must not be programmed in INDIRECT_CTX and
        //!     BB_PER_CTX_PTR buffers.
        //!
        //!
        struct MI_ARB_CHECK_CMD
        {
            union
            {
                struct
                {
                    uint32_t PreParserDisable : __CODEGEN_BITFIELD(0, 0);   //!< PRE_PARSER_DISABLE
                    uint32_t Reserved1 : __CODEGEN_BITFIELD(1, 7);          //!< Reserved
                    uint32_t MaskBits : __CODEGEN_BITFIELD(8, 15);          //!< Mask Bits
                    uint32_t Reserved16 : __CODEGEN_BITFIELD(16, 22);       //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;

            //! \name Local enumerations

            //! \brief PRE_PARSER_DISABLE
            //! \details
            //!     This command allows software to enable or disable pre-parserof
            //!     command buffer functionality from within a command sequence on per
            //!     context basis. This ability allows the command stream to prefetch batch
            //!     buffers that are yet to be parsed by looking ahead in the command FIFO.
            //!     Even with this disabled, driver will have to ensure it does not
            //!     self-modify commands already prefetched into the command buffer within
            //!     the same batch buffer.
            enum PRE_PARSER_DISABLE
            {
                PRE_PARSER_DISABLE_UNNAMED0 = 0,  //!< When reset early fetch and parsing of future command buffersis enabled in hardware when "Pre-Fetch Disable" in GFX_MODE register is not set.
                PRE_PARSER_DISABLE_UNNAMED1 = 1,  //!< When set early fetch and parsing of future command buffers is disabled in hardware.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIARBCHECK = 5,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_ARB_CHECK_CMD()
            {
                DW0.Value = 0x02800000;
                //DW0.PreParserDisable                             = PRE_PARSER_DISABLE_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIARBCHECK;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;
            }

            static const size_t dwSize   = 1;
            static const size_t byteSize = 4;
        };

        //!
        //! \brief MI_LOAD_REGISTER_IMM
        //! \details
        //!     The MI_LOAD_REGISTER_IMM command requests a write of up to a DWord
        //!     constant supplied in the command to the specified Register Offset (i.e.,
        //!     offset into Memory-Mapped Register Range).
        //!       Any offset that is to a destination outside of the GT core will allow
        //!     the parser to continue once the cycle is at the GT boundry and not
        //!     destination.  Any other address will ensure the destination is updated
        //!     prior to parsing the next command
        //!
        //!     Many MMIO bits require the engine to be IDLE prior to updating the
        //!     value.  Command streamer does not implicitly put in a pipeline flush in
        //!     the cases a MMIO bit requires the engine to be IDLE.  In the case there
        //!     was a 3DPRIMITIVE command or GPGPU_WALKER command without any stalling
        //!     PIPE_CONTROL, one must be inserted prior to a MI_LOAD_REGISTER_IMMEDIATE
        //!     that is updating a bit that requires the engine to be IDLE.
        //!
        //!     When executed from a non-privileged batch buffer, MMIO writes are only
        //!     allowed to the registers listed in User Mode Non-Privileged Registers
        //!     for the corresponding engine, any writes targeting the register not
        //!     listed in the User Mode Non-Privileged Register will convert this
        //!     command to a NOOP.
        //!
        //!     The following addresses should NOT be used for LRIs:
        //!       0x8800 - 0x88FF
        //!     >= 0xC0000
        //!
        //!       Limited LRI cycles to the Display Engine (0x40000-0xBFFFF) are
        //!     allowed, but must be spaced to allow only one pending at a time. This
        //!     can be done by issuing an SRM to the same address immediately after each
        //!     LRI.
        //!
        //!     Programming an MMIO register is equivalent to programming a non-pipeline
        //!     state to the hardware and hence an explicit stalling flush needs to be
        //!     programmed prior to programming this command. However for certain MMIO
        //!     registers based on their functionality doing an explicit stalling flush
        //!     is exempted. Listed below are the exempted registers.
        //!       3DPRIM_END_OFFSET - Auto Draw End Offset
        //!     3DPRIM_START_VERTEX - Load Indirect Start Vertex
        //!     3DPRIM_VERTEX_COUNT - Load Indirect Vertex Count
        //!     3DPRIM_INSTANCE_COUNT - Load Indirect Instance Count
        //!     3DPRIM_START_INSTANCE - Load Indirect Start Instance
        //!     3DPRIM_BASE_VERTEX - Load Indirect Base Vertex
        //!     3DPRIM_XP0 - Load Indirect Extended Parameter 0
        //!     3DPRIM_XP1 - Load Indirect Extended Parameter 1
        //!     3DPRIM_XP2 - Load Indirect Extended Parameter 2
        //!
        //!
        struct MI_LOAD_REGISTER_IMM_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);             //!< DWORD_LENGTH
                    uint32_t ByteWriteDisables : __CODEGEN_BITFIELD(8, 11);      //!< Byte Write Disables
                    uint32_t ForcePosted : __CODEGEN_BITFIELD(12, 12);           //!< Force Posted
                    uint32_t Reserved13 : __CODEGEN_BITFIELD(13, 16);            //!< Reserved
                    uint32_t MmioRemapEnable : __CODEGEN_BITFIELD(17, 17);       //!< MMIO_REMAP_ENABLE
                    uint32_t Reserved18 : __CODEGEN_BITFIELD(18, 18);            //!< Reserved
                    uint32_t AddCsMmioStartOffset : __CODEGEN_BITFIELD(19, 19);  //!< ADD_CS_MMIO_START_OFFSET
                    uint32_t Reserved20 : __CODEGEN_BITFIELD(20, 22);            //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);       //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);           //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t Reserved32 : __CODEGEN_BITFIELD(0, 1);       //!< Reserved
                    uint32_t RegisterOffset : __CODEGEN_BITFIELD(2, 22);  //!< Register Offset
                    uint32_t Reserved55 : __CODEGEN_BITFIELD(23, 31);     //!< Reserved
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint32_t DataDword;  //!< Data DWord
                };
                uint32_t Value;
            } DW2;

            //! \name Local enumerations

            //! \brief MMIO_REMAP_ENABLE
            //! \details
            //!     This bit provides a mechanism in HW to remap the MMIO address in the
            //!     MI command to the engine instance on which the command is getting
            //!     executed, remapping in HW is done using engine specific remap table.
            //!     Render and Compute engine share a common remapping table to facilitate
            //!     remapping across engines, where as a dedicated remap table for each of
            //!     Video Decode and Video Enhancement engine class.
            //!       A MMIO remapping table per engine class is created with
            //!     MMIO address belonging to multiple instances of an engine within an
            //!     engine class. However Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       This mode provides mechanism for SW to always use MMIO
            //!     address belonging to fixed instance (instance zero) with in an engine
            //!     class during command buffer creation agnostic to the instance on which
            //!     it will get scheduled. This willalso allow context interoperability
            //!     across instances with in an engine class and extends to across engines
            //!     in case of Render and Compute.
            enum MMIO_REMAP_ENABLE
            {
                MMIO_REMAP_ENABLE_UNNAMED0 = 0,  //!< MMIO remapping will not be applied to the MMIO address.
                MMIO_REMAP_ENABLE_UNNAMED1 = 1,  //!< MMIO remapping will be applied to the MMIO address prior to using for any other functionality of the command.
            };

            //! \brief ADD_CS_MMIO_START_OFFSET
            //! \details
            //!     This bit controls the functionality of the "Register Address" field
            //!     in the command.
            enum ADD_CS_MMIO_START_OFFSET
            {
                ADD_CS_MMIO_START_OFFSET_UNNAMED0 = 0,  //!< "Register Address" field in the command is absolute and not an offset from the executing command streamer MMIO start offset..
                ADD_CS_MMIO_START_OFFSET_UNNAMED1 = 1,  //!< "Register Address" field in the command is treated as an offset from the executing Command Streamers MMIO start offset. Bits [22:2] of the "Register Address" are considered as dword offset to be added to the MMIO start offset of the corresponding command streamer. However, during context restore bits [11:2] of the "Register Address" are considered as dword offset to be added to the MMIO start offset of the corresponding command streamer. Refer "Register Access and User Mode Privilege Access" section to get the list of all the instances of the Command Streamers and their associated MMIO Start Offset's./ Command executed from Ring Buffer or Batch BufferExample: MI_LOAD_REGISTER_IMMEDIATE, ADD_CS_MMIO_START_OFFSET: true, Data:0xABCD, Register Address: 0x00_2000The above command when executed on RenderCS will result in a write to MMIO offset 0x00_4000 (0x00_2000 + 0x00_2000) instead to 0x00_2000. Note that RenderCS MMIO start offset is 0x2000. For illustration table below shows the result of this command executed from few instances of the command streamers from differentengines.<div>
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MILOADREGISTERIMM = 34,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_LOAD_REGISTER_IMM_CMD()
            {
                DW0.Value = 0x11000001;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.MmioRemapEnable                              = MMIO_REMAP_ENABLE_UNNAMED0;
                //DW0.AddCsMmioStartOffset                         = ADD_CS_MMIO_START_OFFSET_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MILOADREGISTERIMM;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;

                DW2.Value = 0x00000000;
            }

            static const size_t dwSize   = 3;
            static const size_t byteSize = 12;
        };

        //!
        //! \brief MI_LOAD_REGISTER_MEM
        //! \details
        //!     The MI_LOAD_REGISTER_MEM command requests from a memory location and
        //!     stores that DWord to a register.
        //!
        //!     The command temporarily halts commands that will cause cycles down the
        //!     3D pipeline.
        //!
        //!     The following addresses should NOT be used for MMIO writes:
        //!       0x8800 - 0x88FF
        //!     >= 0xC0000
        //!
        //!       Limited MMIO writes cycles to the Display Engine 0x40000-0xBFFFF) are
        //!     allowed, but must be spaced to allow only one pending at a time. This
        //!     can be done by issuing an SRM to the same address immediately after each
        //!     MMIO write.
        //!
        //!     This command should not be used within a non-privilege batch buffer to
        //!     access global virtual space, doing so will be treated as privilege
        //!     access violation. Refer "User Mode Privilege Command" in
        //!     MI_BATCH_BUFFER_START command section to know HW behavior on
        //!     encountering privilege access violation.
        //!
        //!     This command is not allowed to update the privilege register range when
        //!     executed from a non-privilege batch buffer.
        //!
        struct MI_LOAD_REGISTER_MEM_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                        //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 15);                         //!< Reserved
                    uint32_t WorkloadPartitionIdOffsetEnable : __CODEGEN_BITFIELD(16, 16);  //!< WORKLOAD_PARTITION_ID_OFFSET_ENABLE
                    uint32_t MmioRemapEnable : __CODEGEN_BITFIELD(17, 17);                  //!< MMIO_REMAP_ENABLE
                    uint32_t Reserved18 : __CODEGEN_BITFIELD(18, 18);                       //!< Reserved
                    uint32_t AddCsMmioStartOffset : __CODEGEN_BITFIELD(19, 19);             //!< ADD_CS_MMIO_START_OFFSET
                    uint32_t Reserved20 : __CODEGEN_BITFIELD(20, 20);                       //!< Reserved
                    uint32_t AsyncModeEnable : __CODEGEN_BITFIELD(21, 21);                  //!< Async Mode Enable
                    uint32_t UseGlobalGtt : __CODEGEN_BITFIELD(22, 22);                     //!< Use Global GTT
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t Reserved32 : __CODEGEN_BITFIELD(0, 1);        //!< Reserved
                    uint32_t RegisterAddress : __CODEGEN_BITFIELD(2, 22);  //!< Register Address
                    uint32_t Reserved55 : __CODEGEN_BITFIELD(23, 31);      //!< Reserved
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint64_t Reserved64 : __CODEGEN_BITFIELD(0, 1);      //!< Reserved
                    uint64_t MemoryAddress : __CODEGEN_BITFIELD(2, 63);  //!< Memory Address
                };
                uint32_t Value[2];
            } DW2_3;

            //! \name Local enumerations

            //! \brief WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            //! \details
            //!     This bit controls the memory read address computation for fetching
            //!     the value fromthe memory to be loaded in to the register.
            //!     The final memory readaddress is computed by
            //!     adding the Workload PartitionID times the "Address Offset"to the memory
            //!     address mentioned in the command.
            //!     Workload Partition ID gets programmed through WPARIDregister and the
            //!     Address Offset gets programmed through CS_MI_ADDRESS_OFFSET.
            //!
            //!     Example: {Final Memory Read
            //!     Address[47:2], 2'b00} = (  Workload Partition ID
            //!     * "Address Offset") + {Memory Write Address [47:2], 2'b00}
            //!
            enum WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            {
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0 = 0,  //!<   There is no offset added to the memory write address.
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED1 = 1,  //!< style="text-align:justify; margin:0in 0in 0.0001pt">    The final memory address is computed based on the   Workload Partition ID.
            };

            //! \brief MMIO_REMAP_ENABLE
            //! \details
            //!     This bit provides a mechanism in HW to remap the MMIO address in the
            //!     MI command to the engine instance on which the command is getting
            //!     executed, remapping in HW is done using engine specific remap table.
            //!     Render and Compute engine share a common remapping table to facilitate
            //!     remapping across engines, where as a dedicated remap table for each of
            //!     Video Decode and Video Enhancement engine class.
            //!       A MMIO remapping table per engine class is created with
            //!     MMIO address belonging to multiple instances of an engine within an
            //!     engine class. However Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       This mode provides mechanism for SW to always use MMIO
            //!     address belonging to fixed instance (instance zero) with in an engine
            //!     class during command buffer creation agnostic to the instance on which
            //!     it will get scheduled. This willalso allow context interoperability
            //!     across instances with in an engine class and extends to across engines
            //!     in case of Render and Compute.
            enum MMIO_REMAP_ENABLE
            {
                MMIO_REMAP_ENABLE_UNNAMED0 = 0,  //!< MMIO remapping will not be applied to the MMIO address.
                MMIO_REMAP_ENABLE_UNNAMED1 = 1,  //!< MMIO remapping will be applied to the MMIO address prior to using for any other functionality of the command.
            };

            //! \brief ADD_CS_MMIO_START_OFFSET
            //! \details
            //!     This bit controls the functionality of the Register Address field in the
            //!     command.
            enum ADD_CS_MMIO_START_OFFSET
            {
                ADD_CS_MMIO_START_OFFSET_UNNAMED0 = 0,  //!< Register Address field in the command is absolute and not an offset from the executing command streamer MMIO start offset.
                ADD_CS_MMIO_START_OFFSET_UNNAMED1 = 1,  //!< Register Address field in the command is treated as an offset from the executing Command Streamers MMIO start offset.Bits [22:2] of the Register Address are considered as dword offset to be added to the MMIO start offset of the corresponding command streamer.Example: MI_LOAD_REGISTER_MEM, ADD_CS_MMIO_START_OFFSET: true, Memory Address:0xABCD, Register Address: 0x1C_0030The above command when executed on RenderCS will result in a write to MMIO offset 0x1C_2030 (0x00_2000 + 0x1C_0030) instead to 0x1C_0030. Note that RenderCS MMIO start offset is 0x2000.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MILOADREGISTERMEM = 41,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_LOAD_REGISTER_MEM_CMD()
            {
                DW0.Value = 0x14800002;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.WorkloadPartitionIdOffsetEnable              = WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0;
                //DW0.MmioRemapEnable                              = MMIO_REMAP_ENABLE_UNNAMED0;
                //DW0.AddCsMmioStartOffset                         = ADD_CS_MMIO_START_OFFSET_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MILOADREGISTERMEM;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;

                DW2_3.Value[0] = DW2_3.Value[1] = 0x00000000;
            }

            static const size_t dwSize   = 4;
            static const size_t byteSize = 16;
        };

        //!
        //! \brief MI_LOAD_REGISTER_REG
        //! \details
        //!     The MI_LOAD_REGISTER_REG command reads from a source register location
        //!     and writes that value to a destination register location.
        //!
        //!     Any offset that is to a destination outside of the GT core will allow
        //!     the parser to continue once the cycle is at the GT boundry and not
        //!     destination. Any other address will ensure the destination is updated
        //!     prior to parsing the next command
        //!
        //!
        //!     The command temporarily halts commands that will cause cycles down the
        //!     3D pipeline.
        //!
        //!     Destination register with mask implemented (Ex: Some registers have bits
        //!     [31:16] as mask bits and bits[15:0] as data) will not get updated unless
        //!     the  value read from source register has the bits corresponding to the
        //!     mask bits set. Note that any mask implemented register when read returns
        //!     "0" for the bits corresponding to mask location. When the source and
        //!     destination are mask implemented registers, destination register will
        //!     not get updated with the source register contents.
        //!
        //!     This command is not allowed to update the privilege register range when
        //!     executed from a non-privilege batch buffer.
        //!
        struct MI_LOAD_REGISTER_REG_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                        //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 15);                         //!< Reserved
                    uint32_t MmioRemapEnableSource : __CODEGEN_BITFIELD(16, 16);            //!< MMIO_REMAP_ENABLE_SOURCE
                    uint32_t MmioRemapEnableDestination : __CODEGEN_BITFIELD(17, 17);       //!< MMIO_REMAP_ENABLE_DESTINATION
                    uint32_t AddCsMmioStartOffsetSource : __CODEGEN_BITFIELD(18, 18);       //!< ADD_CS_MMIO_START_OFFSET_SOURCE
                    uint32_t AddCsMmioStartOffsetDestination : __CODEGEN_BITFIELD(19, 19);  //!< ADD_CS_MMIO_START_OFFSET_DESTINATION
                    uint32_t Reserved20 : __CODEGEN_BITFIELD(20, 22);                       //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t Reserved32 : __CODEGEN_BITFIELD(0, 1);              //!< Reserved
                    uint32_t SourceRegisterAddress : __CODEGEN_BITFIELD(2, 22);  //!< Source Register Address
                    uint32_t Reserved55 : __CODEGEN_BITFIELD(23, 31);            //!< Reserved
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint32_t Reserved64 : __CODEGEN_BITFIELD(0, 1);                   //!< Reserved
                    uint32_t DestinationRegisterAddress : __CODEGEN_BITFIELD(2, 22);  //!< Destination Register Address
                    uint32_t Reserved87 : __CODEGEN_BITFIELD(23, 31);                 //!< Reserved
                };
                uint32_t Value;
            } DW2;

            //! \name Local enumerations

            //! \brief MMIO_REMAP_ENABLE_SOURCE
            //! \details
            //!     This bit provides a mechanism in HW to remap the "Source
            //!     Register"MMIO address in the MI command to the engine instance on which
            //!     the command is getting executed, remapping in HW is done using engine
            //!     specific remap table. Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       A MMIO remapping table per engine class is created with
            //!     MMIO address belonging to multiple instances of an engine within an
            //!     engine class. However Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       This mode provides mechanism for SW to always use MMIO
            //!     address belonging to fixed instance (instance zero) with in an engine
            //!     class during command buffer creation agnostic to the instance on which
            //!     it will get scheduled. This willalso allow context interoperability
            //!     across instances with in an engine class and extends to across engines
            //!     in case of Render and Compute.
            enum MMIO_REMAP_ENABLE_SOURCE
            {
                MMIO_REMAP_ENABLE_SOURCE_UNNAMED0 = 0,  //!< MMIO remapping will not be applied to the MMIO address.
                MMIO_REMAP_ENABLE_SOURCE_UNNAMED1 = 1,  //!< MMIO remapping will be applied to the MMIO address prior to using for any other functionality of the command.
            };

            //! \brief MMIO_REMAP_ENABLE_DESTINATION
            //! \details
            //!     This bit provides a mechanism in HW to remap the " Destination
            //!     Register" MMIO address in the MI command to the engine instance on which
            //!     the command is getting executed, remapping in HW is done using engine
            //!     specific remap table. Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       A MMIO remapping table per engine class is created with
            //!     MMIO address belonging to multiple instances of an engine within an
            //!     engine class. However Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       This mode provides mechanism for SW to always use MMIO
            //!     address belonging to fixed instance (instance zero) with in an engine
            //!     class during command buffer creation agnostic to the instance on which
            //!     it will get scheduled. This willalso allow context interoperability
            //!     across instances with in an engine class and extends to across engines
            //!     in case of Render and Compute.
            enum MMIO_REMAP_ENABLE_DESTINATION
            {
                MMIO_REMAP_ENABLE_DESTINATION_UNNAMED0 = 0,  //!< MMIO remapping will not be applied to the MMIO address.
                MMIO_REMAP_ENABLE_DESTINATION_UNNAMED1 = 1,  //!< MMIO remapping will be applied to the MMIO address prior to using for any other functionality of the command.
            };

            //! \brief ADD_CS_MMIO_START_OFFSET_SOURCE
            //! \details
            //!     This bit controls the functionality of the Register Address Source
            //!     field in the command.
            enum ADD_CS_MMIO_START_OFFSET_SOURCE
            {
                ADD_CS_MMIO_START_OFFSET_SOURCE_UNNAMED0 = 0,  //!< Register Address field in the command is absolute and not an offset from the executing command streamer MMIO start offset.
                ADD_CS_MMIO_START_OFFSET_SOURCE_UNNAMED1 = 1,  //!< Source Register Address field in the command is treated as an offset from the executing Command Streamers MMIO start offset. Bits [22:2] of the Source Register Address are considered as dword offset to be added to the MMIO start offset of the corresponding command streamer./>Example: MI_LOAD_REGISTER_REGISTER_REG, DEST_ADD_CS_MMIO_START_OFFSET: false, SRC_ADD_CS_MMIO_START_OFFSET:true, Source Register Address:0x1C_0130, Destination Register Address: 0x1C_0030/>The above command when executed on RenderCS will result in a MMIO read from 0x1C _2130 instead of read from 0x1C_0130 and write to MMIO offset 0x1C_0030. Note that RenderCS MMIO start offset is 0x2000.
            };

            //! \brief ADD_CS_MMIO_START_OFFSET_DESTINATION
            //! \details
            //!     This bit controls the functionality of the Register Address
            //!     Destination field in the command.
            enum ADD_CS_MMIO_START_OFFSET_DESTINATION
            {
                ADD_CS_MMIO_START_OFFSET_DESTINATION_UNNAMED0 = 0,  //!< Destination Register Address field in the command is absolute and not an offset from the executing command streamer MMIO start offset.
                ADD_CS_MMIO_START_OFFSET_DESTINATION_UNNAMED1 = 1,  //!< Destination Register Address field in the command is treated as an offset from the executing Command Streamers MMIO start offset. Bits [22:2] of the Destination Register Address are considered as dword offset to be added to the MMIO start offset of the corresponding command streamer./>Example: MI_LOAD_REGISTER_REGISTER_REG, DEST_ADD_CS_MMIO_START_OFFSET: true, SRC_ADD_CS_MMIO_START_OFFSET:true, Source Register Address:0x1C_0130, Destination Register Address: 0x1C_0030/>The above command when executed on RenderCS will result in a MMIO read from 0x1C_2130 (0x00_2000 + 0x1C_0130) and write to MMIO offset 0x1C_2030 (0x00_2000 + 0x1C_0030) instead of read from 0x1C_0130 and write to 0x1C_0030. Note that RenderCS MMIO start offset is 0x2000.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MILOADREGISTERREG = 42,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_LOAD_REGISTER_REG_CMD()
            {
                DW0.Value = 0x15000001;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.MmioRemapEnableSource                        = MMIO_REMAP_ENABLE_SOURCE_UNNAMED0;
                //DW0.MmioRemapEnableDestination                   = MMIO_REMAP_ENABLE_DESTINATION_UNNAMED0;
                //DW0.AddCsMmioStartOffsetSource                   = ADD_CS_MMIO_START_OFFSET_SOURCE_UNNAMED0;
                //DW0.AddCsMmioStartOffsetDestination              = ADD_CS_MMIO_START_OFFSET_DESTINATION_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MILOADREGISTERREG;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;

                DW2.Value = 0x00000000;
            }

            static const size_t dwSize   = 3;
            static const size_t byteSize = 12;
        };

        //!
        //! \brief MI_STORE_REGISTER_MEM
        //! \details
        //!     The MI_STORE_REGISTER_MEM command requests a register read from a
        //!     specified memory mapped register location in the device and store of
        //!     that DWord to memory. The register address is specified along with the
        //!     command to perform the read.
        //!
        //!     The command temporarily halts command execution.
        //!     The memory address for the write is snooped on the host bus.
        //!     This command should not be used from within a "non-privilege" batch
        //!     buffer to access global virtual space. doing so will be treated as
        //!     privilege access violation. Refer "User Mode Privilege Command" in
        //!     MI_BATCH_BUFFER_START command section to know HW behavior on
        //!     encountering privilege access violation. This command can be used within
        //!     ring buffers and/or "privilege" batch buffers to access global virtual
        //!     space.
        //!     This command will cause undefined data to be written to memory if given
        //!     register addresses for the PGTBL_CTL_0 or FENCE registers.
        //!
        //!
        struct MI_STORE_REGISTER_MEM_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                        //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 15);                         //!< Reserved
                    uint32_t WorkloadPartitionIdOffsetEnable : __CODEGEN_BITFIELD(16, 16);  //!< WORKLOAD_PARTITION_ID_OFFSET_ENABLE
                    uint32_t MmioRemapEnable : __CODEGEN_BITFIELD(17, 17);                  //!< MMIO_REMAP_ENABLE
                    uint32_t Reserved18 : __CODEGEN_BITFIELD(18, 18);                       //!< Reserved
                    uint32_t AddCsMmioStartOffset : __CODEGEN_BITFIELD(19, 19);             //!< ADD_CS_MMIO_START_OFFSET
                    uint32_t Reserved20 : __CODEGEN_BITFIELD(20, 20);                       //!< Reserved
                    uint32_t PredicateEnable : __CODEGEN_BITFIELD(21, 21);                  //!< Predicate Enable
                    uint32_t UseGlobalGtt : __CODEGEN_BITFIELD(22, 22);                     //!< Use Global GTT
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t Reserved32 : __CODEGEN_BITFIELD(0, 1);        //!< Reserved
                    uint32_t RegisterAddress : __CODEGEN_BITFIELD(2, 22);  //!< Register Address
                    uint32_t Reserved55 : __CODEGEN_BITFIELD(23, 31);      //!< Reserved
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint64_t Reserved64 : __CODEGEN_BITFIELD(0, 1);      //!< Reserved
                    uint64_t MemoryAddress : __CODEGEN_BITFIELD(2, 63);  //!< Memory Address
                };
                uint32_t Value[2];
            } DW2_3;

            //! \name Local enumerations

            //! \brief WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            //! \details
            //!     style="text-align:justify; margin:0in 0in 0.0001pt"><span
            //!     style="font-size:11pt">style="font-family:Calibri,
            //!     sans-serif">This bit controls the memory
            //!     write address computation for the store data update. The final memory
            //!     write address is computed by adding the   Workload
            //!     Partition ID<span
            //!     style="font-family:Calibri, sans-serif">
            //!     times the "Address Offset"to the memory address mentioned in the
            //!     command. Workload Partition ID<span
            //!     style="font-size:11pt">style="font-family:Calibri,
            //!     sans-serif"> gets programmed in the
            //!     WPARIDregister <span
            //!     style="font-family:&quot;Calibri&quot;,sans-serif">and the Address
            //!     Offset gets programmed through CS_MI_ADDRESS_OFFSET
            //!     registerstyle="font-family:Calibri,
            //!     sans-serif">.
            //!     style="text-align:justify; margin:0in 0in 0.0001pt">
            //!     style="text-align:justify; margin:0in 0in 0.0001pt"><span
            //!     style="font-size:11pt">style="font-family:Calibri,
            //!     sans-serif">Example: {Final Memory Write
            //!     Address[47:2], 2'b00} = (  Workload Partition
            //!     IDstyle="font-family:Calibri,
            //!     sans-serif">* Address Offset) + {Memory
            //!     Write Address [47:2], 2'b00}
            //!     style="text-align:justify; margin:0in 0in 0.0001pt">
            enum WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            {
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0 = 0,  //!<   There is no offset added to the memory write address.
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED1 = 1,  //!<   The final memory address is computed based on the Virtual Engine ID.
            };

            //! \brief MMIO_REMAP_ENABLE
            //! \details
            //!     This bit provides a mechanism in HW to remap the MMIO address in the
            //!     MI command to the engine instance on which the command is getting
            //!     executed, remapping in HW is done using engine specific remap table.
            //!     Render and Compute engine share a common remapping table to facilitate
            //!     remapping across engines, where as a dedicated remap table for each of
            //!     Video Decode and Video Enhancement engine class.
            //!       A MMIO remapping table per engine class is created with
            //!     MMIO address belonging to multiple instances of an engine within an
            //!     engine class. However Render and Compute engine share a common remapping
            //!     table to facilitate remapping across engines, where as a dedicated remap
            //!     table for each of Video Decode and Video Enhancement engine class.
            //!       This mode provides mechanism for SW to always use MMIO
            //!     address belonging to fixed instance (instance zero) with in an engine
            //!     class during command buffer creation agnostic to the instance on which
            //!     it will get scheduled. This will also allow context interoperability
            //!     across instances with in an engine class and extends to across engines
            //!     in case of Render and Compute.
            enum MMIO_REMAP_ENABLE
            {
                MMIO_REMAP_ENABLE_UNNAMED0 = 0,  //!< MMIO remapping will not be applied to the MMIO address.
                MMIO_REMAP_ENABLE_UNNAMED1 = 1,  //!< MMIO remapping will be applied to the MMIO address prior to using for any other functionality of the command.
            };

            //! \brief ADD_CS_MMIO_START_OFFSET
            //! \details
            //!     This bit controls the functionality of the Register Address field in
            //!     the command.
            enum ADD_CS_MMIO_START_OFFSET
            {
                ADD_CS_MMIO_START_OFFSET_UNNAMED0 = 0,  //!< Register Address field in the command is absolute and not an offset from the executing command streamer MMIO start offset.
                ADD_CS_MMIO_START_OFFSET_UNNAMED1 = 1,  //!< Register Address field in the command is treated as an offset from the executing Command Streamers MMIO start offset. Bits [22:2] of the Register Address are considered as dword offset to be added to the MMIO start offset of the corresponding command streamer./>Example: MI_STORE_REGISTER_MEM, ADD_CS_MMIO_START_OFFSET: true, Memory Address:0xABCD, Register Address: 0x1C_0030/>The above command when executed on RenderCS will result in updating the memory address with the content of the MMIO offset 0x1C_2030 (0x00_2000 + 0x1C_0030) instead to 0x1C_0030. Note that RenderCS MMIO start offset is 0x2000.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MISTOREREGISTERMEM = 36,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_STORE_REGISTER_MEM_CMD()
            {
                DW0.Value = 0x12000002;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.WorkloadPartitionIdOffsetEnable              = WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0;
                //DW0.MmioRemapEnable                              = MMIO_REMAP_ENABLE_UNNAMED0;
                //DW0.AddCsMmioStartOffset                         = ADD_CS_MMIO_START_OFFSET_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MISTOREREGISTERMEM;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;

                DW2_3.Value[0] = DW2_3.Value[1] = 0x00000000;
            }

            static const size_t dwSize   = 4;
            static const size_t byteSize = 16;
        };

        //!
        //! \brief MI_BATCH_BUFFER_START
        //! \details
        //!     The MI_BATCH_BUFFER_START command is used to initiate the execution of
        //!     commands stored in a batch buffer. For restrictions on the location of
        //!     batch buffers, see Batch Buffers in the Device Programming Interface
        //!     chapter of MI Functions. The batch buffer can be specified as privileged
        //!     or non-privileged, determining the operations considered valid when
        //!     initiated from within the buffer and any attached (chained) batch
        //!     buffers. See Batch Buffer Protection in the Device Programming Interface
        //!     chapter of MI Functions.
        //!
        //!     A batch buffer initiated with this command must end either with a
        //!     MI_BATCH_BUFFER_END command or by chaining to another batch buffer with
        //!     an MI_BATCH_BUFFER_START command.
        //!
        //!     It is essential that the address location beyond the current page be
        //!     populated inside the GTT. HW performs over-fetch of the command
        //!     addresses and any over-fetch requires a valid TLB entry. A single extra
        //!     page beyond the batch buffer is sufficient.
        //!
        //!       Hardware has DMA engine to fetch the command buffer data from memory.
        //!     DMA engine pre-fetches eight cacheline worth of command data in to its
        //!     storage and keeps it ready to be executed, it keeps fetching command
        //!     data as and when space is available in the storage upon execution of
        //!     commands. In case of batch buffer execution, DMA engine stops
        //!     prefetching the command data only on executing MI_BATCH_BUFFER_END
        //!     command and MI_BATCH_BUFFER_START in case of chained batch buffers.
        //!     Software must ensure memory pages are made available accounting for the
        //!     hardware pre-fetched memory addresses.
        //!
        //!       Example:
        //!
        //!       When MI_BATCH_BUFFER_END or MI_BATCH_BUFFER_START is more than eight
        //!     cachelines (512 Bytes) away from the page boundary, nothing special has
        //!     to be done by SW.
        //!
        //!       When MI_BATCH_BUFFER_END or MI_BATCH_BUFFER_START is less than or
        //!     equal to eight cachelines (512 Bytes) from the page boundary, SW must
        //!     ensure the next page is made available as part of the batch buffer. This
        //!     will ensure the memory address is populated and will not result in fault
        //!     when the hardware ends up pre-fetching data from the next page prior to
        //!     execution of MI_BATCH_BUFFER_END or MI_BATCH_BUFFER_START command.
        //!
        //!     SW must ensure it buffers the size of the batch buffer includes
        //!     additional buffer equal to the command buffer beyond the end. The
        //!     command buffer for the command streamer is 0.5KB.
        //!
        //!     SW must ensure it buffers the size of the batch buffer includes
        //!     additional buffer equal to the command buffer beyond the end. The
        //!     command buffer for the command streamer is 1 KB.
        //!
        struct MI_BATCH_BUFFER_START_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);            //!< DWORD_LENGTH,
                    uint32_t AddressSpaceIndicator : __CODEGEN_BITFIELD(8, 8);  //!< ADDRESS_SPACE_INDICATOR,
                    uint32_t Reserved9 : __CODEGEN_BITFIELD(9, 31);             //!< Reserved,
                } Obj0;
                struct
                {
                    uint32_t Reserved0 : __CODEGEN_BITFIELD(0, 8);                             //!< Reserved,
                    uint32_t Reserved9 : __CODEGEN_BITFIELD(9, 9);                             //!< Reserved,
                    uint32_t Reserved10 : __CODEGEN_BITFIELD(10, 14);                          //!< Reserved,
                    uint32_t PredicationEnable : __CODEGEN_BITFIELD(15, 15);                   //!< Predication Enable,
                    uint32_t Reserved16 : __CODEGEN_BITFIELD(16, 18);                          //!< Reserved,
                    uint32_t EnableCommandCache : __CODEGEN_BITFIELD(19, 19);                  //!< ENABLE_COMMAND_CACHE,
                    uint32_t PoshEnable : __CODEGEN_BITFIELD(20, 20);                          //!< POSH_ENABLE,
                    uint32_t PoshStart : __CODEGEN_BITFIELD(21, 21);                           //!< POSH_START,
                    uint32_t Reserved22 : __CODEGEN_BITFIELD(22, 22);                          //!< Reserved,
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                     //!< MI_COMMAND_OPCODE,
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                         //!< COMMAND_TYPE,
                } Obj1;
                struct
                {
                    uint32_t Reserved0 : __CODEGEN_BITFIELD(0, 21);                //!< Reserved,
                    uint32_t NestedLevelBatchBuffer : __CODEGEN_BITFIELD(22, 22);  //!< NESTED_LEVEL_BATCH_BUFFER, MI_MODE:NestedBatchBufferEnable=='1'
                    uint32_t Reserved23 : __CODEGEN_BITFIELD(23, 31);              //!< Reserved, MI_MODE:NestedBatchBufferEnable=='1'
                } Obj2;
                struct
                {
                    uint32_t Reserved0 : __CODEGEN_BITFIELD(0, 21);                //!< Reserved, MI_MODE:NestedBatchBufferEnable=='1'
                    uint32_t SecondLevelBatchBuffer : __CODEGEN_BITFIELD(22, 22);  //!< SECOND_LEVEL_BATCH_BUFFER, MI_MODE:NestedBatchBufferEnable=='0'
                    uint32_t Reserved23 : __CODEGEN_BITFIELD(23, 31);              //!< Reserved, MI_MODE:NestedBatchBufferEnable=='0'
                } Obj3;
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint64_t Reserved32 : __CODEGEN_BITFIELD(0, 1);                //!< Reserved
                    uint64_t BatchBufferStartAddress : __CODEGEN_BITFIELD(2, 63);  //!< Batch Buffer Start Address
                };
                uint32_t Value[2];
            } DW1_2;

            //! \name Local enumerations

            //! \brief ADDRESS_SPACE_INDICATOR
            //! \details
            //!     Batch buffers accessed via PPGTT are considered as non-privileged.
            //!     Certain operations (e.g., MI_STORE_DATA_IMM commands to GGTT memory) are
            //!     prohibited within non-privileged buffers. More details mentioned in User
            //!     Mode Privileged command section. When MI_BATCH_BUFFER_START command is
            //!     executed from within a batch buffer (i.e., is a "chained" or "second
            //!     level" batch buffer command), the current active batch buffer's "Address
            //!     Space Indicator" and this field determine the "Address Space Indicator"
            //!     of the next buffer in the chain.
            //!
            //!     Chained or Second level batch buffer can be in GGTT or
            //!     PPGTT if the parent batch buffer is in GGTT.

            //!     Chained or Second level batch buffer can only be in
            //!     PPGTT if the parent batch buffer is in PPGTT. This is enforced by
            //!     Hardware.

            //!
            enum ADDRESS_SPACE_INDICATOR
            {
                ADDRESS_SPACE_INDICATOR_GGTT  = 0,  //!< This batch buffer is located in GGTT memory and is privileged.
                ADDRESS_SPACE_INDICATOR_PPGTT = 1,  //!< This batch buffer is located in PPGTT memory and is Non-Privileged.
            };

            enum ENABLE_COMMAND_CACHE
            {
                ENABLE_COMMAND_CACHE_UNNAMED0 = 0,  //!< Command Cache disable
                ENABLE_COMMAND_CACHE_UNNAMED1 = 1,  //!< Command Cache enabled
            };

            //! \brief POSH_ENABLE
            //! \details
            //!     <p> "POSH Enable" field in the MI_BATCH_BUFFER_START command is a hint
            //!     to POCS to traverse (parse, don’t execute) the batch buffer to look for
            //!     "POSH Start" batch buffers. "POSH Enable" field is only inherited to the
            //!     chained batch buffer and doesn’t get inherit to the next level batch
            //!     buffers unlike "POSH Start" field. "POSH Enable" field must be
            //!     explicitly set in the MI_BATCH_BUFFER_START command which calls the next
            //!     level batch buffers in order for the POCS to parse them to look for
            //!     "POSH Start" batch buffers. "POSH Start" field  takes precedence over
            //!     the "POSH Enable" field in POCS.</p>
            //!     <p>Example:</p>
            //!     <ul>
            //!         <li>Once "POSH Enable" is encountered in a first level batch buffer,
            //!     POCS will traverse the whole of the first level batch buffers (including
            //!     chained first level) to check for "POSH Start" field in
            //!     MI_BATCH_BUFFER_START command. POCS by default will not traverse the
            //!     second level batch buffers. SW must explicitly set the "POSH Enable"
            //!     field for the second level batch buffer called from first level batch
            //!     buffer if the second level batch buffer have to be traversed by
            //!     POCS.</li>
            //!         <li>Similarly, Once "POSH Enable" is encountered in a second level
            //!     batch buffer, POCS will traverse the whole of the second level batch
            //!     buffers (including chained second level) to check for "POSH Start" field
            //!     in MI_BATCH_BUFFER_START command. POCS by default will not traverse the
            //!     third level batch buffers. SW must explicitly set the "POSH Enable"
            //!     field for the third level batch buffer called from second level batch
            //!     buffer if the third level batch buffer have to be traversed by
            //!     POCS.</li>
            //!         <li>Similarly, Once "POSH Enable" is encountered in a third level
            //!     batch buffer, POCS will traverse the whole of the third level batch
            //!     buffers (including chained second level) to check for "POSH Start" field
            //!     in MI_BATCH_BUFFER_START command.</li>
            //!     </ul>
            //!
            //!     <p>RCS ignores "POSH Enable" field and has no implications due to the
            //!     "POSH Enable" field set in the MI_BATCH_BUFFER_START command.</p>
            enum POSH_ENABLE
            {
                POSH_ENABLE_UNNAMED0 = 0,  //!< Batch buffer is  not "POSH Enable".
                POSH_ENABLE_UNNAMED1 = 1,  //!< Batch buffer is "POSH Enable"/
            };

            //! \brief POSH_START
            //! \details
            //!     <p>Batch buffers dedicated to be executed by POSH pipe are indicated by
            //!     setting the field "POSH Start" in the MI_BATCH_BUFFER_START command
            //!     header. Once "POSH Start" is set in a batch buffer all the following
            //!     chained batch buffers and next level batch buffers will implicitly
            //!     inherit the "POSH Start" field value. Once "POSH Start" is set in a
            //!     batch buffer all the following command sequences are to be
            //!     <b>executed</b> by POCS until the corresponding batch buffer sequencing
            //!     is terminated through
            //!     MI_BATCH_BUFFER_END/MI_CONDITIONAL_BATCH_BUFFER_END command.</p>
            //!     <p>Example:</p>
            //!     <ul>
            //!         <li>Once "POSH Start" is encountered in a first level batch buffer
            //!     by POCS, it will get reset only when the first level batch buffer
            //!     execution is terminated through batch buffer end and the command
            //!     execution sequence goes back to the ring buffer,</li>
            //!         <li>Similarly, once "POSH Start" is encountered in a second level
            //!     batch buffer by POCS, it will get reset only when the second level batch
            //!     buffer execution is terminated through batch buffer end and the command
            //!     execution sequence goes back to the first level buffer,</li>
            //!         <li>Similarly, once when "POSH Start" is encountered in a third
            //!     level batch buffer by POCS, it will get reset only when the third level
            //!     batch buffer execution is terminated through batch buffer end and the
            //!     command execution sequence goes back to the second level batch
            //!     buffer.</li>
            //!     </ul>
            //!
            //!     <p>Command sequences executed from the "POSH Start" batch buffer may
            //!     lead to chained batch buffers or next level batch buffers.  Batch
            //!     buffers executed by POCS may have MI Commands, 3DSATE commands and
            //!     3DPRIMTIVE commands for POSH pipe. RCS on parsing MI_BATCH_BUFFER_START
            //!     command with "POSH Start" enabled NOOPS the command and moves on the
            //!     following command.</p>
            enum POSH_START
            {
                POSH_START_UNNAMED0 = 0,  //!< Batch buffer is not "POSH Start" enabled.
                POSH_START_UNNAMED1 = 1,  //!< Batch buffer is "POSH Start" enabled.
            };

            //! \brief NESTED_LEVEL_BATCH_BUFFER
            //! \details
            //!     If this bit is set, the command streamer will move to the next level
            //!     of batch buffer. Once it executes a MI_BATCH_BUFFER_END in the next
            //!     level, it will return to the batch buffer executing this command and
            //!     execute the next command.
            //!     If clear then itwill remain in the same batch buffer level and on
            //!     executingMI_BATCH_BUFFER_END, it will return to the previous level.
            //!     Otherwise known as batch buffer chaining.
            //!     Hardware supports threelevels of nesting, namely First Level, Second
            //!     Level and Third Level.
            //!     This bit must not be set in any of the MI_BATCH_BUFFER_START commands
            //!     programmed as part of the 3rd level batch buffer's command sequence.
            //!
            enum NESTED_LEVEL_BATCH_BUFFER
            {
                NESTED_LEVEL_BATCH_BUFFER_CHAIN  = 0,  //!< Stay in the same batch buffer level.
                NESTED_LEVEL_BATCH_BUFFER_NESTED = 1,  //!< Move to the next level of batch buffer.
            };

            //! \brief SECOND_LEVEL_BATCH_BUFFER
            //! \details
            //!     The command streamer contains three storage elements; one for the
            //!     ring head address, one for the batch head address, and one for the
            //!     second level batch head address. When performing batch buffer chaining,
            //!     hardware simply updates the head pointer of the first level batch
            //!     address storage. There is no stack in hardware. When this bit is set,
            //!     hardware uses the 2nd level batch head address storage element. Chaining
            //!     of second level batch buffers is supported. A chained second level batch
            //!     buffer is inferred in hardware when aMI_BATCH_BUFFER_START command with
            //!     "Second Level Batch Buffer" bit field set is executed from a second
            //!     level batch buffer, hardware simply updates the head pointer of the
            //!     second level batch address storage. Upon MI_BATCH_BUFFER_END, it will
            //!     automatically return to the first level batch buffer address. This
            //!     allows hardware to mimic a simple 3-level stack.
            enum SECOND_LEVEL_BATCH_BUFFER
            {
                SECOND_LEVEL_BATCH_BUFFER_FIRSTLEVELBATCH  = 0,  //!< Place the batch buffer address in the 1st (traditional) level batch address storage element.
                SECOND_LEVEL_BATCH_BUFFER_SECONDLEVELBATCH = 1,  //!< Place the batch buffer address in the second-level batch address storage element.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIBATCHBUFFERSTART = 49,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_BATCH_BUFFER_START_CMD()
            {
                DW0.Value = 0;
                DW0.Obj0.DwordLength = GetOpLength(dwSize);
                DW0.Obj0.AddressSpaceIndicator = ADDRESS_SPACE_INDICATOR_GGTT;
                DW0.Obj1.EnableCommandCache = ENABLE_COMMAND_CACHE_UNNAMED0;
                DW0.Obj1.PoshEnable = POSH_ENABLE_UNNAMED0;
                DW0.Obj1.PoshStart = POSH_START_UNNAMED0;
                DW0.Obj1.MiCommandOpcode = MI_COMMAND_OPCODE_MIBATCHBUFFERSTART;
                DW0.Obj1.CommandType = COMMAND_TYPE_MICOMMAND;
                DW0.Obj2.NestedLevelBatchBuffer = NESTED_LEVEL_BATCH_BUFFER_CHAIN;
                DW0.Obj3.SecondLevelBatchBuffer = SECOND_LEVEL_BATCH_BUFFER_FIRSTLEVELBATCH;
                DW1_2.Value[0] = DW1_2.Value[1] = 0x00000000;
                //DW0.Value                                        = 0x18800001;
                //DW0.Obj0.DwordLength                             = GetOpLength(dwSize);
                //DW0.Obj0.AddressSpaceIndicator                   = ADDRESS_SPACE_INDICATOR_GGTT;
                //DW0.Obj0.IndirectAddressEnable                   = INDIRECT_ADDRESS_ENABLE_USEINLINEADDRESS;
                //DW0.Obj0.EnableCommandCache                      = ENABLE_COMMAND_CACHE_UNNAMED0;
                //DW0.Obj1.NestedLevelBatchBuffer                  = NESTED_LEVEL_BATCH_BUFFER_CHAIN;
                //DW0.Obj2.SecondLevelBatchBuffer                  = SECOND_LEVEL_BATCH_BUFFER_FIRSTLEVELBATCH;
                //DW0.Obj3.MiCommandOpcode                         = MI_COMMAND_OPCODE_MIBATCHBUFFERSTART;
                //DW0.Obj3.CommandType                             = COMMAND_TYPE_MICOMMAND;
            }

            static const size_t dwSize   = 3;
            static const size_t byteSize = 12;
        };

        //!
        //! \brief MI_SET_PREDICATE
        //! \details
        //!
        //!     This command provides a mechanism to NOOP a section of commands
        //!     programmed in the command buffer. This command on execution evaluates
        //!     the predication status based on the following predication conditions
        //!     enabled.
        //!
        //!     Predication status gets set if any of the above fields satisfy the
        //!     predicate condition. On predicate status set, HW NOOPS the subsequent
        //!     commands parsed until the predicate status is re-evaluated and reset on
        //!     executing next MI_SET_PREDICATE command. However the following commands
        //!     are exception which can be programmed to be or not be predicated as part
        //!     of the predication flow enforced by MI_SET_PREDICATE command.
        //!
        //!     MI_BATCH_BUFFER_START
        //!
        //!     MI_BATCH_BUFFER_END
        //!
        //!     MI_CONDITIONAL_BATCH_BUFFER_END
        //!
        //!     MI_SET_PREDICATE command will always get executed by HW irrespective of
        //!     the predication status.
        //!
        //!       MI_SET_PREDCIATE commands predication status is context save/restored
        //!     through MMIO register MI_SET_PREDICATE_RESULT to retain its
        //!     functionality across the context switches. Predication based of
        //!     MI_SET_PREDICATE_RESULT is only applied to the commands that are
        //!     executed from Ring Buffer and Batch Buffer and doesnt apply to any other
        //!     sources (context restore, Work Around Batch Buffers) of commands.
        //!
        //!       MI_SET_PREDICATE predication scope must be confined within a Batch
        //!     Buffer to set of commands.
        //!     MI_SET_PREDICATE with Predicate Enable Must always have a corresponding
        //!     MI_SET_PREDICATE with Predicate Disable within the same Batch Buffer.
        //!
        //!
        struct MI_SET_PREDICATE_CMD
        {
            union
            {
                struct
                {
                    uint32_t PredicateEnable : __CODEGEN_BITFIELD(0, 3);        //!< PREDICATE_ENABLE
                    uint32_t PredicateEnableWparid : __CODEGEN_BITFIELD(4, 5);  //!< PREDICATE_ENABLE_WPARID
                    uint32_t Reserved6 : __CODEGEN_BITFIELD(6, 22);             //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);      //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);          //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;

            //! \name Local enumerations

            enum PREDICATE_ENABLE
            {
                PREDICATE_ENABLE_PREDICATEDISABLE   = 0,   //!< Predication is Disabled and CS will process commands as usual.
                PREDICATE_ENABLE_NOOPONRESULT2CLEAR = 1,   //!< Following Commands will be NOOPED by CS only if the MI_PREDICATE_RESULT_2 is clear.
                PREDICATE_ENABLE_NOOPONRESULT2SET   = 2,   //!< Following Commands will be NOOPED by CS only if the MI_PREDICATE_RESULT_2 is set.
                PREDICATE_ENABLE_NOOPALWAYS         = 15,  //!< Following Commands will be NOOPED by CS unconditionally.
            };

            //! \brief PREDICATE_ENABLE_WPARID
            //! \details
            //!
            //!     This field enables the predication based on the outcome
            //!     of value resulting in bitwise AND of the bits in the WPARID and the
            //!     PREDICATION_MASK Mask Register. WPARID and PREDICATION_MASK are
            //!     non-privileged registers and context save/restored on a context
            //!     switch.
            //!
            enum PREDICATE_ENABLE_WPARID
            {
                PREDICATE_ENABLE_WPARID_NOOPNEVER           = 0,  //!< The predication status due to this field doesnt contribute to the overall predication status of MI_SET_PREDICATE command.
                PREDICATE_ENABLE_WPARID_NOOPONZEROVALUE     = 1,  //!< Predicate if (WPARID AND PREDICATE_MASK) == 0
                PREDICATE_ENABLE_WPARID_NOOPONNON_ZEROVALUE = 2,  //!< Predicate if (WPARID AND PREDICATE_MASK) != 0
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MISETPREDICATE = 1,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_SET_PREDICATE_CMD()
            {
                DW0.Value = 0x00800000;
                //DW0.PredicateEnable                              = PREDICATE_ENABLE_NOOPNEVER;
                //DW0.PredicateEnableWparid                        = PREDICATE_ENABLE_WPARID_NOOPNEVER;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MISETPREDICATE;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;
            }

            static const size_t dwSize   = 1;
            static const size_t byteSize = 4;
        };

        //!
        //! \brief MI_COPY_MEM_MEM
        //! \details
        //!     The MI_COPY_MEM_MEM command reads a DWord from memory and stores the
        //!     value of that DWord to back to memory.   The source and destination
        //!     addresses are specified in the command. The command temporarily halts
        //!     command execution.
        //!
        //!     This command should not be used within a "non-privileged" batch buffer
        //!     to access global virtual space; doing so will be treated as privilege
        //!     access violation. Refer to the "User Mode Privilege Command" in
        //!     MI_BATCH_BUFFER_START command section to learn more about HW behavior on
        //!     encountering a privilege access violation.  This command can be used
        //!     within ring buffers and/or privilege batch buffers to access global
        //!     virtual space.
        //!
        struct MI_COPY_MEM_MEM_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 20);                 //!< Reserved
                    uint32_t UseGlobalGttDestination : __CODEGEN_BITFIELD(21, 21);  //!< USE_GLOBAL_GTT_DESTINATION
                    uint32_t UseGlobalGttSource : __CODEGEN_BITFIELD(22, 22);       //!< USE_GLOBAL_GTT_SOURCE
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);          //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);              //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint64_t Reserved32 : __CODEGEN_BITFIELD(0, 1);                 //!< Reserved
                    uint64_t DestinationMemoryAddress : __CODEGEN_BITFIELD(2, 63);  //!< Destination Memory Address
                };
                uint32_t Value[2];
            } DW1_2;
            union
            {
                struct
                {
                    uint64_t Reserved96 : __CODEGEN_BITFIELD(0, 1);            //!< Reserved
                    uint64_t SourceMemoryAddress : __CODEGEN_BITFIELD(2, 63);  //!< Source Memory Address
                };
                uint32_t Value[2];
            } DW3_4;

            //! \name Local enumerations

            //! \brief USE_GLOBAL_GTT_DESTINATION
            //! \details
            //!     It is allowed for this bit to be set when executing this command from a
            //!     privileged (secure) batch buffer or ring buffer. This bit must be clear
            //!     when programmed from within a non-privileged batch buffer. This bit must
            //!     be 1 if the Per Process GTT Enable bit is clear.
            enum USE_GLOBAL_GTT_DESTINATION
            {
                USE_GLOBAL_GTT_DESTINATION_PERPROCESSGRAPHICSADDRESS = 0,  //!< No additional details
                USE_GLOBAL_GTT_DESTINATION_GLOBALGRAPHICSADDRESS     = 1,  //!< This command will use the global GTT to translate the Address and this command must be executing from a privileged (secure) batch buffer.
            };

            //! \brief USE_GLOBAL_GTT_SOURCE
            //! \details
            //!     It is allowed for this bit to be set when executing this command from a
            //!     privileged (secure) batch buffer or ring buffer. This bit must be clear
            //!     when programmed from within a non-privileged batch buffer. This bit must
            //!     be 1 if the Per Process GTT Enable bit is clear.
            enum USE_GLOBAL_GTT_SOURCE
            {
                USE_GLOBAL_GTT_SOURCE_PERPROCESSGRAPHICSADDRESS = 0,  //!< No additional details
                USE_GLOBAL_GTT_SOURCE_GLOBALGRAPHICSADDRESS     = 1,  //!< This command will use the global GTT to translate the Address and this command must be executing from a privileged (secure) batch buffer.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIMEMTOMEM = 46,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_COPY_MEM_MEM_CMD()
            {
                DW0.Value = 0x17000003;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.UseGlobalGttDestination                      = USE_GLOBAL_GTT_DESTINATION_PERPROCESSGRAPHICSADDRESS;
                //DW0.UseGlobalGttSource                           = USE_GLOBAL_GTT_SOURCE_PERPROCESSGRAPHICSADDRESS;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MICOPYMEMMEM;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1_2.Value[0] = DW1_2.Value[1] = 0x00000000;

                DW3_4.Value[0] = DW3_4.Value[1] = 0x00000000;
            }

            static const size_t dwSize   = 5;
            static const size_t byteSize = 20;
        };

        //!
        //! \brief MI_STORE_DATA_IMM
        //! \details
        //!     The MI_STORE_DATA_IMM command requests a write of the QWord constant
        //!     supplied in the packet to the specified Memory Address. As the write
        //!     targets a System Memory Address, the write operation is coherent with
        //!     the CPU cache (i.e., the processor cache is snooped).
        //!
        //!     This command supports writing to multiple consecutive dwords or qwords
        //!     memory locations from the starting address.
        //!
        //!     This command should not be used within a "non-privilege" batch buffer to
        //!     access global virtual space, doing so will be treated as privilege
        //!     access violation. Refer "User Mode Privilege Command" in
        //!     MI_BATCH_BUFFER_START command section to know HW behavior on
        //!     encountering privilege access violation. This command can be used within
        //!     ring buffers and/or privilege batch buffers to access global virtual
        //!     space.
        //!
        //!     This command can be used for general software synchronization through
        //!     variables in cacheable memory (i.e., where software does not need to
        //!     poll un-cached memory or device registers).
        //!
        //!     This command simply initiates the write operation with command execution
        //!     proceeding normally. Although the write operation is guaranteed to
        //!     complete eventually, there is no mechanism to synchronize command
        //!     execution with the completion (or even initiation) of these operations.
        //!
        struct MI_STORE_DATA_IMM_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 9);                        //!< DWORD_LENGTH
                    uint32_t ForceWriteCompletionCheck : __CODEGEN_BITFIELD(10, 10);        //!< FORCE_WRITE_COMPLETION_CHECK
                    uint32_t WorkloadPartitionIdOffsetEnable : __CODEGEN_BITFIELD(11, 11);  //!< WORKLOAD_PARTITION_ID_OFFSET_ENABLE
                    uint32_t Reserved12 : __CODEGEN_BITFIELD(12, 20);                       //!< Reserved
                    uint32_t StoreQword : __CODEGEN_BITFIELD(21, 21);                       //!< Store Qword
                    uint32_t UseGlobalGtt : __CODEGEN_BITFIELD(22, 22);                     //!< Use Global GTT
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint64_t CoreModeEnable : __CODEGEN_BITFIELD(0, 0);  //!< Core Mode Enable
                    uint64_t Reserved33 : __CODEGEN_BITFIELD(1, 1);      //!< Reserved
                    uint64_t Address : __CODEGEN_BITFIELD(2, 63);        //!< Address
                };
                uint32_t Value[2];
            } DW1_2;
            union
            {
                struct
                {
                    uint32_t DataDword0;  //!< Data DWord 0
                };
                uint32_t Value;
            } DW3;
            union
            {
                struct
                {
                    uint32_t DataDword1;  //!< Data DWord 1
                };
                uint32_t Value;
            } DW4;

            //! \name Local enumerations

            //! \brief FORCE_WRITE_COMPLETION_CHECK
            //! \details
            //!     This bit controls the write completion checks done by command streamer
            //!     on executing this command.
            enum FORCE_WRITE_COMPLETION_CHECK
            {
                FORCE_WRITE_COMPLETION_CHECK_UNNAMED0 = 0,  //!< All writes resulting from this command are posted writes and no ordering are completion of writes is explicitly guaranteed by command streamer.
                FORCE_WRITE_COMPLETION_CHECK_UNNAMED1 = 1,  //!< Followng the last write from this command, Command Streamer will wait for all previous writes are completed and in global observable domain before moving to next command.
            };

            //! \brief WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            //! \details
            //!     This bit controls the memory write address computation for the store data update.
            //!     The final memory write address is computed by adding the
            //!     Workload Partition ID times the Address
            //!     Offset to the memory address mentioned in the command.
            //!     Workload Partition ID gets programmed in
            //!     the WPARIDregister and the Address Offset gets programmed through
            //!     CS_MI_ADDRESS_OFFSET register.
            //!     Example for store dword/qword:
            //!     {Final Memory Write Address[47:2], `b00} = (
            //!     Workload Partition ID* "Address Offset" + {Memory Write Address [47:2],`b00}
            //!
            enum WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            {
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0 = 0,  //!<   There is no offset added to the memory write address.
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED1 = 1,  //!< style="text-align:justify; margin:0in 0in 0.0001pt">    The final memory address is computed based on the Virtual Engine ID.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MISTOREDATAIMM = 32,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_STORE_DATA_IMM_CMD()
            {
                DW0.Value = 0x10000003;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.ForceWriteCompletionCheck                    = FORCE_WRITE_COMPLETION_CHECK_UNNAMED0;
                //DW0.WorkloadPartitionIdOffsetEnable              = WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MISTOREDATAIMM;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1_2.Value[0] = DW1_2.Value[1] = 0x00000000;

                DW3.Value = 0x00000000;

                DW4.Value = 0x00000000;
            }

            static const size_t dwSize   = 5;
            static const size_t byteSize = 20;
        };

        //!
        //! \brief MI_SEMAPHORE_SIGNAL
        //! \details
        //!     An engine on executing this command generates a signal (interrupt) to
        //!     the GUC (scheduler or FW) by reporting the Producer Token Number
        //!     programmed in SEMAPHORE_TOKEN register. Each engine implements its own
        //!     SEMAPHORE_TOKEN register. SEMAPHORE_TOKEN register is privileged and
        //!     context save/restored. Scheduler can take appropriate action on decoding
        //!     the reported Producer Token Number. Typically MI_ATOMIC (non-posted)
        //!     command will be used to update the memory semaphore before signaling the
        //!     consumer context.
        //!       Each engine implements SEMAPHORE_SIGNAL_PORT register for receiving
        //!     semaphore signal from the scheduler (SW or FW). A write to the
        //!     SEMAPHORE_SIGNAL_PORT with data as 0xFFFF_FFFF is decoded as semaphore
        //!     signal received by the corresponding engine. An engine waiting on
        //!     un-successful MI_SEMAPHORE_WAIT (signal mode) command will reacquire the
        //!     semaphore data from memory and re-evaluate the semaphore comparison on
        //!     receiving the semaphore signal. SEMAPHORE_SIGNAL_PORT register is
        //!     privileged. Writing to the SEMAPHORE_SIGNAL_PORT of an idle engine (no
        //!     context) does not trigger any action in HW and is of no use.
        //!       SEMAPHORE_TOKEN, MI_SEMAPHORE_SIGNAL, SEMAPHORE_SIGNAL_PORT and
        //!     MI_SEMAPHORE_WAIT together can be used to create semaphores between
        //!     producer context and consumer context. MI_SEMPAHORE_SIGNAL command from
        //!     a producer context can be used to signal a consumer context waiting on
        //!     MI_SEMAPHORE_WAIT (signal mode) command through scheduler (SW or FW).
        //!       Typically MI_ATOMIC (non-posted) command will be used to update the
        //!     memory semaphore by the producer context before signaling the consumer
        //!     context.
        //!     Scheduler on receiving the signal will process the Producer Token Number
        //!     and if required will signal the consumer context running on an engine by
        //!     writing 0xFFFF_FFFF to the corresponding engines SEMAPHORE_SIGNAL_PORT.
        //!     A consumer context will wait on MI_SEMAPHORE_WAIT (signal mode) command
        //!     until the semaphore comparison is successful. An engine waiting on
        //!     un-successful MI_SEMAPHORE_WAIT (signal mode) command will reacquire the
        //!     semaphore data from memory and re-evaluate the semaphore comparison on
        //!     receiving the semaphore signal.MI_SEMAPHORE_WAIT command has Wait Token
        //!     Number as inline data programmed by the SW. Context switched out an
        //!     un-successful MI_SEMAPHORE_WAIT command will report Wait Token Number as
        //!     Wait Detail field in the CSB structure.
        //!
        //!     Workaround
        //!
        //!     : Post-Sync operation bit must not be set when Target Engine Select is
        //!     set to RCS.
        //!
        struct MI_SEMAPHORE_SIGNAL_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);          //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 20);           //!< Reserved
                    uint32_t PostSyncOperation : __CODEGEN_BITFIELD(21, 21);  //!< POST_SYNC_OPERATION
                    uint32_t Reserved22 : __CODEGEN_BITFIELD(22, 22);         //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);    //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);        //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t Reserved32;  //!< Reserved
                };
                uint32_t Value;
            } DW1;

            //! \name Local enumerations

            //! \brief POST_SYNC_OPERATION
            //! \details
            //!     Any desired pipeline flush operation can be achieved by programming
            //!     PIPE_CONTROL command prior to this command.
            //!       When this bit is set Command Streamer sends a flush down
            //!     the pipe and the atomic operation is saved as post sync operation.
            //!     Command streamer goes on executing the following commands. Atomic
            //!     operation saved as post sync operation is executed at some point later
            //!     on completion of corresponding flush issued.
            //!       When this bit is set atomic semaphore signal operation will
            //!     be out of order with rest of the MI commands programmed in the ring
            //!     buffer or batch buffer, it will be in order with respect to the post
            //!     sync operations resulting due to PIPE_CONTROL command.
            enum POST_SYNC_OPERATION
            {
                POST_SYNC_OPERATION_NOPOSTSYNCOPERATION = 0,  //!< Command is executed as usual.
                POST_SYNC_OPERATION_POSTSYNCOPERATION   = 1,  //!< MI_SEMAPHORE_SIGNAL command is executed as a pipelined PIPE_CONTROL flush command with Semaphore Signal as post sync operation. Flush completion only guarantees the workload prior to this command is pushed till Windower unit and completion of any outstanding flushes issued prior to this command.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MISEMAPHORESIGNAL = 27,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_SEMAPHORE_SIGNAL_CMD()
            {
                DW0.Value = 0x0d800000;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.PostSyncOperation                            = POST_SYNC_OPERATION_NOPOSTSYNCOPERATION;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MISEMAPHORESIGNAL;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;
            }

            static const size_t dwSize   = 2;
            static const size_t byteSize = 8;
        };

        //!
        //! \brief MI_SEMAPHORE_WAIT
        //! \details
        //!
        //!     This command supports memory based Semaphore WAIT. Memory based
        //!     semaphores will be used for synchronization between the Producer and the
        //!     Consumer contexts. Producer and Consumer Contexts could be running on
        //!     different engines or on the same engine inside GT. Producer Context
        //!     implements a Signal and Consumer context implements a Wait.
        //!     Command Streamer on parsing this command fetches data from the Semaphore
        //!     Address mentioned in this command and compares it with the inline
        //!     Semaphore Data Dword.
        //!     If comparison passes, the command streamer moves to the next command.
        //!     If comparison fails Command streamer switches out the context. Context
        //!     switch can be inhibited by setting "Inhibit Synchronous Context Switch"
        //!     in CTXT_SR_CTL register.
        //!     If "Inhibit Synchronous context Switch" is enabled and comparison fails,
        //!     Command Streamer evaluates the Compare Operation based on the Wait Mode
        //!     until the compare operation is true or Wait is canceled by SW.
        //!     CS generates semaphore wait interrupt to the scheduler when
        //!     MI_SEMAPHORE_WAIT command is un-successful and when "Inhibit Synchronous
        //!     Context Switch" is set. Scheduler can use this interrupt to preempt the
        //!     context waiting on semaphore wait.
        //!
        //!     MI_SEMAPHORE_WAIT command also supports register based Semaphore WAIT.
        //!     Command Streamer on parsing this command fetches data from the MMIO
        //!     offset mentioned in this command and compares it with the inline
        //!     Semaphore Data Dword. This functionality is supported when Register Poll
        //!     bit is set in the command header. In register poll mode of operation
        //!     Wait Mode supported is always Poll mode and no Signal mode is supported.
        //!       If comparison passes, the command streamer moves to the next command.
        //!     Unlike in Memory based semaphore, there is no context switch on an
        //!     un-successful semaphore wait in Register Poll mode, however preemption
        //!     is supported on unsuccessful semaphore wait in Register Poll mode.
        //!     Semaphore wait interrupt is not generated by default on wait
        //!     un-successful in Register Poll mode. However interrupt generation can be
        //!     enabled by setting debug mode bit Semaphore Interrupt Enable in Register
        //!     Poll Mode in register CSFE_CHICKEN1
        //!     Also unlike in Memory based semaphore, generation of an interrupt for a
        //!     semaphore wait in "Register Poll" mode is not dependent on the value of
        //!     bit "Inhibit Synchronous Context Switch" in register "CTXT_SR_CTL"
        //!     Register Poll mode of Semaphore Wait command operation is non-privileged
        //!     and will be supported from PPGTT batch buffers.
        //!     HW will trigger Render DOP CG on semaphore wait unsuccessful by default
        //!     and can be disabled if not desired by programming Register Poll Mode
        //!     Semaphore Wait Event IDLE message Disable bit in INSTPM register. Note
        //!     that Render DOP CG will not be triggered on register semaphore wait
        //!     un-successfull from INDIRECT_CTX pointer or BB_PER_CTX_PTR buffers.
        //!
        //!     MI_SEMAPHORE_WAIT command must not be used in the middle of a tile pass
        //!     on the posh pipe.
        //!
        //!     Workaround
        //!
        //!     : [All Command Streamers][Ring Buffer Mode of Scheduling]:
        //!     MI_SEMAPHORE_WAIT command must be always programmed with Wait Mode set
        //!     to Polling Mode Or MI_SEMAPHORE_WAIT command with Wait Mode set to
        //!     Polling Mode can be programmed when Semaphore Wait Event IDLE message
        //!     Disable bit in RC_PSMI_CTRL register is set to disable Idle messaging on
        //!     unsuccessful MI_SEMPAHORE_WAIT.
        //!
        struct MI_SEMAPHORE_WAIT_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                        //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 11);                         //!< Reserved
                    uint32_t CompareOperation : __CODEGEN_BITFIELD(12, 14);                 //!< COMPARE_OPERATION
                    uint32_t WaitMode : __CODEGEN_BITFIELD(15, 15);                         //!< WAIT_MODE
                    uint32_t RegisterPollMode : __CODEGEN_BITFIELD(16, 16);                 //!< REGISTER_POLL_MODE
                    uint32_t IndirectSemaphoreDataDword : __CODEGEN_BITFIELD(17, 17);       //!< INDIRECT_SEMAPHORE_DATA_DWORD
                    uint32_t WorkloadPartitionIdOffsetEnable : __CODEGEN_BITFIELD(18, 18);  //!< WORKLOAD_PARTITION_ID_OFFSET_ENABLE
                    uint32_t Reserved19 : __CODEGEN_BITFIELD(19, 21);                       //!< Reserved
                    uint32_t MemoryType : __CODEGEN_BITFIELD(22, 22);                       //!< MEMORY_TYPE
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t SemaphoreDataDword;  //!< Semaphore Data Dword
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint64_t Reserved64 : __CODEGEN_BITFIELD(0, 1);         //!< Reserved
                    uint64_t SemaphoreAddress : __CODEGEN_BITFIELD(2, 63);  //!< Semaphore Address
                };
                uint32_t Value[2];
            } DW2_3;
            union
            {
                struct
                {
                    uint32_t Reserved128 : __CODEGEN_BITFIELD(0, 1);      //!< Reserved
                    uint32_t WaitTokenNumber : __CODEGEN_BITFIELD(2, 9);  //!< Wait Token Number
                    uint32_t Reserved138 : __CODEGEN_BITFIELD(10, 31);    //!< Reserved
                };
                uint32_t Value;
            } DW4;

            //! \name Local enumerations

            //! \brief COMPARE_OPERATION
            //! \details
            //!     This field specifies the operation that will be executed to create the
            //!     result that will either allow the context to continue or wait.
            enum COMPARE_OPERATION
            {
                COMPARE_OPERATION_SADGREATERTHANSDD        = 0,  //!< If Indirect fetched data is greater than inline data then continue.
                COMPARE_OPERATION_SADGREATERTHANOREQUALSDD = 1,  //!< If Indirect fetched data is greater than or equal to inline data then continue.
                COMPARE_OPERATION_SADLESSTHANSDD           = 2,  //!< If Indirect fetched data is less than inline data then continue.
                COMPARE_OPERATION_SADLESSTHANOREQUALSDD    = 3,  //!< If Indirect fetched data is less than or equal to inline data then continue.
                COMPARE_OPERATION_SADEQUALSDD              = 4,  //!< If Indirect fetched data is equalto inline data then continue.
                COMPARE_OPERATION_SADNOTEQUALSDD           = 5,  //!< If Indirect fetched data is not equal to inline data then continue.
            };

            //! \brief WAIT_MODE
            //! \details
            //!     This bit specifies the WAIT behavior when the semaphore comparison fails
            //!     and before the context is switched out.
            enum WAIT_MODE
            {
                WAIT_MODE_SIGNALMODE  = 0,  //!< In this mode HW will reacquire the semaphore data from memory for evaluating semaphore wait condition on receiving SIGNAL.Scheduler or SW can generate a SIGNAL to an engine by writing a value 0xFFFF_FFFF to the engines corresponding SEMAPHORE_SIGNAL_PORT register.
                WAIT_MODE_POLLINGMODE = 1,  //!< In this mode HW periodically reads the semaphore data from memory for comparison until it is context switched out. Periodicity will be mentioned in a SEMA_WAIT_POLL register.
            };

            //! \brief REGISTER_POLL_MODE
            //! \details
            //!     This field control the seamphore wait behavior of polling from memory
            //!     vs MMIO register.
            enum REGISTER_POLL_MODE
            {
                REGISTER_POLL_MODE_MEMORYPOLL   = 0,  //!< In this mode HW will functional as in regular mode and checks for semaphore data in memory.
                REGISTER_POLL_MODE_REGISTERPOLL = 1,  //!< In this mode HW periodically reads the semaphore data from MMIO register instead of memory for comparison until the condition is satisfied. Periodicity will be mentioned in a SEMA_WAIT_POLL register.When operating in register poll mode, DW2 Semaphore Address (bits 22:2) carries the register MMIO offset to be polled.In register poll mode Memory Type field of this command are ignored by HW.
            };

            //! \brief INDIRECT_SEMAPHORE_DATA_DWORD
            //! \details
            //!     This bit controls the "Semaphore Data Dword" to be used for comparison
            //!     in register poll mode of operation.
            enum INDIRECT_SEMAPHORE_DATA_DWORD
            {
                INDIRECT_SEMAPHORE_DATA_DWORD_UNNAMED0 = 0,  //!< Inline data from the command is considered as "Semaphore Data Dword" for comparison.
                INDIRECT_SEMAPHORE_DATA_DWORD_UNNAMED1 = 1,  //!< Value available in GPR0 (Lower Dword) register is considered as "Semaphore Data Dword" for comparison instead of inline data in the command.
            };

            //! \brief WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            //! \details
            //!     This bit controls the memory read address computation for fetching the dat value from the
            //!     memory for semaphore comparison. The final memory readaddress is
            //!     computed by adding the Workload Partition ID"times the Address Offset to
            //!     the memory address mentioned in the command. Workload Partition ID gets
            //!     programmed through WPARID register and the Address Offset gets
            //!     programmed through CS_MI_ADDRESS_OFFSET register.
            //!
            //!     Example: Final Memory Read
            //!     Address[47:2] = ( Workload Partition ID * Address Offset)
            //!     + Memory Read Address[47:2]
            enum WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            {
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0 = 0,  //!<   There is no offset added to the memory read address.
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED1 = 1,  //!< style="text-align:justify; margin:0in 0in 0.0001pt">    The final memory address is computed based on the Virtual Engine ID.
            };

            //! \brief MEMORY_TYPE
            //! \details
            //!     This bit will be ignored and treated as if clear when executing from a
            //!     non-privileged batch buffer. It is allowed for this bit to be clear when
            //!     executing this command from a privileged (secure) batch buffer. This bit
            //!     must be 1 if the Per Process GTT Enable bit is clear.
            enum MEMORY_TYPE
            {
                MEMORY_TYPE_PERPROCESSGRAPHICSADDRESS = 0,  //!< No additional details
                MEMORY_TYPE_GLOBALGRAPHICSADDRESS     = 1,  //!< This command will use the global GTT to translate the Address and this command must beexecuting from a privileged (secure) batch buffer.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MISEMAPHOREWAIT = 28,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_SEMAPHORE_WAIT_CMD()
            {
                DW0.Value = 0x0e010003;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.CompareOperation                             = COMPARE_OPERATION_SADGREATERTHANSDD;
                //DW0.WaitMode                                     = WAIT_MODE_SIGNALMODE;
                //DW0.RegisterPollMode                             = REGISTER_POLL_MODE_REGISTERPOLL;
                //DW0.IndirectSemaphoreDataDword                   = INDIRECT_SEMAPHORE_DATA_DWORD_UNNAMED0;
                //DW0.WorkloadPartitionIdOffsetEnable              = WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0;
                //DW0.MemoryType                                   = MEMORY_TYPE_PERPROCESSGRAPHICSADDRESS;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MISEMAPHOREWAIT;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;

                DW2_3.Value[0] = DW2_3.Value[1] = 0x00000000;

                DW4.Value = 0x00000000;
            }

            static const size_t dwSize   = 5;
            static const size_t byteSize = 20;
        };

        //!
        //! \brief MI_CONDITIONAL_BATCH_BUFFER_END
        //! \details
        //!     The MI_CONDITIONAL_BATCH_BUFFER_END command is used to conditionally
        //!     terminate the execution of commands stored in a batch buffer initiated
        //!     using a MI_BATCH_BUFFER_START command.Termination of the current level
        //!     of batch buffer from which MI_CONDITIONAL_BATCH_BUFFER_END is executed
        //!     or termination of all levels of batch buffer behavior is controlled by
        //!     the End Current Batch Buffer Level bit in the command header.
        //!
        //!     Any updates to the memory location exercised by this command must be
        //!     ensured to be coherent in memory prior to programming of this command.
        //!     If the memory location is being updated by a prior executed MI command
        //!     (ex: MI_STORE_REGISTER_MEM ..etc) on the same engine, SW must follow one
        //!     of the below programming note prior to programming of this command to
        //!     ensure data is coherent in memory.
        //!
        //!     Option1: Programming of "4" dummy MI_STORE_DATA_IMM (write to scratch
        //!     space) commands prior to programming of this command. Example:
        //!     MI_STORE_REGISTE_MEM (0x2288, 0x2CF0_0000)   MI_STORE_DATA_IMM (4 times)
        //!     (Dummy data, Scratch Address)
        //!     MI_CONDITIONAL_BATCH_BUFFER_END(0x2CF0_0000)
        //!
        //!     Option2: Programming of a PIPE_CONTROL with Post-Sync Operation selected
        //!     to Write Immediate Data to scratch space address with Command Streamer
        //!     Stall Enable set prior to programming of this command. Example:
        //!     MI_STORE_REGISTE_MEM (0x2288, 0x2CF0_0000)   PIPE_CONTROL (Stall, Write
        //!     Immediate Data), MI_CONDITIONAL_BATCH_BUFFER_END(0x2CF0_0000)
        //!
        //!     Option3: MI_ATOMIC (write to scratch space) with "CS STALL" set prior to
        //!     programming of this command. Example: MI_STORE_REGISTE_MEM (0x2288,
        //!     0x2CF0_0000)   MI_ATOMIC (MOV, Dummy data, Scratch Address),
        //!     MI_CONDITIONAL_BATCH_BUFFER_END(0x2CF0_0000)
        //!
        struct MI_CONDITIONAL_BATCH_BUFFER_END_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                               //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 11);                                //!< Reserved
                    uint32_t CompareOperation : __CODEGEN_BITFIELD(12, 14);                        //!< COMPARE_OPERATION
                    uint32_t PredicateEnable : __CODEGEN_BITFIELD(15, 15);                         //!< Predicate Enable
                    uint32_t Reserved16 : __CODEGEN_BITFIELD(16, 17);                              //!< Reserved
                    uint32_t EndCurrentBatchBufferLevel : __CODEGEN_BITFIELD(18, 18);              //!< END_CURRENT_BATCH_BUFFER_LEVEL
                    uint32_t CompareMaskMode : __CODEGEN_BITFIELD(19, 19);                         //!< COMPARE_MASK_MODE
                    uint32_t Reserved20 : __CODEGEN_BITFIELD(20, 20);                              //!< Reserved20
                    uint32_t CompareSemaphore : __CODEGEN_BITFIELD(21, 21);                        //!< COMPARE_SEMAPHORE
                    uint32_t UseGlobalGtt : __CODEGEN_BITFIELD(22, 22);                            //!< USE_GLOBAL_GTT
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);                         //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                             //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t CompareDataDword;  //!< Compare Data Dword
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint64_t Reserved64 : __CODEGEN_BITFIELD(0, 2);       //!< Reserved
                    uint64_t CompareAddress : __CODEGEN_BITFIELD(3, 63);  //!< Compare Address
                };
                uint32_t Value[2];
            } DW2_3;

            //! \name Local enumerations

            //! \brief COMPARE_OPERATION
            //! \details
            //!     This field specifies the operation that will be executed to create
            //!     the result that will either allow to continue or terminate the batch
            //!     buffer.
            //!       />
            //!       MAD = Memory Address Data Dword
            //!       IDD  =Inline Data Dword
            enum COMPARE_OPERATION
            {
                COMPARE_OPERATION_MADGREATERTHANIDD        = 0,  //!< If Indirect fetched data is greater than inline data then continue.
                COMPARE_OPERATION_MADGREATERTHANOREQUALIDD = 1,  //!< If Indirect fetched data is greater than or equal to inline data then continue.
                COMPARE_OPERATION_MADLESSTHANIDD           = 2,  //!< If Indirect fetched data is less than inline data then continue.
                COMPARE_OPERATION_MADLESSTHANOREQUALIDD    = 3,  //!< If Indirect fetched data is less than or equal to inline data then continue.
                COMPARE_OPERATION_MADEQUALIDD              = 4,  //!< If Indirect fetched data is equal to inline data then continue.
                COMPARE_OPERATION_MADNOTEQUALIDD           = 5,  //!< If Indirect fetched data is not equal to inline data then continue.
            };

            //! \brief END_CURRENT_BATCH_BUFFER_LEVEL
            //! \details
            //!     This field specifies if the current level of the batch buffer execution
            //!     must or the complete batch (including parent) buffer execution must be
            //!     terminated on compare operation evaluating false.
            enum END_CURRENT_BATCH_BUFFER_LEVEL
            {
                END_CURRENT_BATCH_BUFFER_LEVEL_UNNAMED0 = 0,  //!< Execution of the command result in termination of all levels of batch buffer and command execution returns to the ring buffer.
                END_CURRENT_BATCH_BUFFER_LEVEL_UNNAMED1 = 1,  //!< Execution of the command results in terminating the batch buffer level from which this command has been executed and command execution returns to the previous/parent batch buffer.Ex:when executed from a first level batch buffer, execution of batch buffer is terminated and the command execution resumes to the ring buffer. This is similar to as if MI_BATCH_BUFFER_END command was executed from first level batch buffer.when executed from a second level batch buffer, execution of second level batch buffer is terminated and the command execution resumes to the first level batch buffer. This is similar to as if MI_BATCH_BUFFER_END command was executed from second level batch buffer.when executed from a third level batch buffer (if supported), execution of third level batch buffer is terminated and the command execution resumes to the second level batch buffer. This is similar to as if MI_BATCH_BUFFER_END command was executed from third level batch buffer.
            };

            //! \brief COMPARE_MASK_MODE
            //! \details
            //!     When "Compare Mask Mode" is enabled, "Compare Address" must be qword
            //!     aligned.
            enum COMPARE_MASK_MODE
            {
                COMPARE_MASK_MODE_COMPAREMASKMODEDISABLED = 0,  //!< Compare address points to Dword in memory consisting of Data Dword(DW0). HW will compare Data Dword(DW0) against Semaphore Data Dword.
                COMPARE_MASK_MODE_COMPAREMASKMODEENABLED  = 1,  //!< Compare address points to Qword in memory consisting of compare Mask (DW0) and Data Dword(DW1). HW will do AND operation on Mask(DW0) with Data Dword(DW1) and then compare the result against Semaphore Data Dword.
            };

            //! \brief COMPARE_BUFFER_ENC_MEMORY_READ_ENABLE
            //! \details
            //!     If set, the read to memory for the comparison value will be from
            //!     enc memory. Otherwise the fetch is made from non-enc memory.
            enum COMPARE_BUFFER_ENC_MEMORY_READ_ENABLE
            {
                COMPARE_BUFFER_ENC_MEMORY_READ_ENABLE_UNNAMED0 = 0,  //!< No additional details
            };

            //! \brief COMPARE_SEMAPHORE
            //! \details
            //!     This bit provides a means to enable or disable compare operation.
            enum COMPARE_SEMAPHORE
            {
                COMPARE_SEMAPHORE_UNNAMED0 = 0,  //!< This command will be treated as NOOP and usual batch buffer execution flow continues.
                COMPARE_SEMAPHORE_UNNAMED1 = 1,  //!< The data from the Compare Data Dword (inline) is compared to the data in memory pointed by the Compare Address as per the Compare Operation. Based on the outcome of the compare operation it may result in either continue execution of the batch buffer or it may result in termination of the batch buffer.
            };

            //! \brief USE_GLOBAL_GTT
            //! \details
            //!     If set, this command will use the global GTT to translate the Compare
            //!     Address and this command must be executing from a privileged
            //!     (secure) batch buffer. If clear, the PPGTT will be used to translate the
            //!     Compare Address.
            enum USE_GLOBAL_GTT
            {
                USE_GLOBAL_GTT_UNNAMED0 = 0,  //!< No additional details
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MICONDITIONALBATCHBUFFEREND = 54,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_CONDITIONAL_BATCH_BUFFER_END_CMD()
            {
                DW0.Value = 0x1b000002;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.CompareOperation                             = COMPARE_OPERATION_MADGREATERTHANIDD;
                //DW0.EndCurrentBatchBufferLevel                   = END_CURRENT_BATCH_BUFFER_LEVEL_UNNAMED0;
                //DW0.CompareMaskMode                              = COMPARE_MASK_MODE_COMPAREMASKMODEDISABLED;
                //DW0.CompareBufferEncMemoryReadEnable             = COMPARE_BUFFER_ENC_MEMORY_READ_ENABLE_UNNAMED0;
                //DW0.CompareSemaphore                             = COMPARE_SEMAPHORE_UNNAMED0;
                //DW0.UseGlobalGtt                                 = USE_GLOBAL_GTT_UNNAMED0;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MICONDITIONALBATCHBUFFEREND;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;

                DW2_3.Value[0] = DW2_3.Value[1] = 0x00000000;
            }

            static const size_t dwSize   = 4;
            static const size_t byteSize = 16;
        };

        //!
        //! \brief MI_ATOMIC
        //! \details
        //!     MI_ATOMIC is used to carry atomic operation on data in graphics memory.
        //!     Atomic operations are supported on data granularity of 4B, 8B and 16B.
        //!     The atomic operation leads to a read-modify-write operation on the data
        //!     in graphics memory with the option of returning value. The data in
        //!     graphics memory is modified by doing arithmetic and logical operation
        //!     with the inline/indirect data provided with the MI_ATOMIC command.
        //!     Inline/Indirect provided in the command can be one or two operands based
        //!     on the atomic operation. Ex: Atomic-Compare operation needs two operands
        //!     while Atomic-Add operation needs single operand and Atomic-increment
        //!     requires no operand. Refer "Atomics" sub-section of "L3 Cache and URB"
        //!     section for detailed atomic operations supported. Atomic
        //!     operations can be enabled to return value by setting "Return Data
        //!     Control" field in the command, return data is stored to CS_GPR
        //!     registers.
        //!       CS_GPR4/5 registers are updated with memory Return Data based on the
        //!     "Data Size". Each GPR register is qword in size and occupies two MMIO
        //!     registers.
        //!       Note: Any references to CS_GPR registers in the command should be
        //!     understood as the CS_GPR registers belonging to the corresponding
        //!     engines *CS_GPR registers.
        //!
        //!     Indirect Source Operands:
        //!
        //!       Operand1 is sourced from [CS_GPR1, CS_GPR0]
        //!       Operand2 is sourced from [CS_GPR3, CS_GPR2]
        //!       Read return Data is stored in [CS_GPR_5, CS_GPR4]
        //!
        //!     When "Data Size" is DWORD lower dword of CS_GPR4 (Qword) is updated with
        //!     the dword data returned from memory. When "Data Size" is QWORD only
        //!     CS_GPR4 (Qword) is updated with the qword data returned from memory.
        //!     When the data size is OCTWORD CS_GPR4/5 are updated with the OCTWORD
        //!     data returned from memory. CS_GPR4 is loaded with lower qword returned
        //!     from memory and CS_GPR5 is loaded with upper qword returned from memory.
        //!
        //!     When Inline Data mode is not set, Dwords 3..10 must not be included as
        //!     part of the command. Dword Length field in the header must be programmed
        //!     accordingly.
        //!
        //!     When Inline Data Mode is set, Dwords3..10 must be included based on the
        //!     Data Size field of the header. Both Operand-1 and Operand-2 dwords must
        //!     be programmed based on the Data Size field. Operand-2 must be programmed
        //!     to 0x0 if the atomic operation doesn't require it. Dword Length field in
        //!     the header must be programmed accordingly.
        //!
        struct MI_ATOMIC_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);          //!< DWORD_LENGTH
                    uint32_t AtomicOpcode : __CODEGEN_BITFIELD(8, 15);        //!< ATOMIC OPCODE
                    uint32_t ReturnDataControl : __CODEGEN_BITFIELD(16, 16);  //!< Return Data Control
                    uint32_t CsStall : __CODEGEN_BITFIELD(17, 17);            //!< CS STALL
                    uint32_t InlineData : __CODEGEN_BITFIELD(18, 18);         //!< Inline Data
                    uint32_t DataSize : __CODEGEN_BITFIELD(19, 20);           //!< DATA_SIZE
                    uint32_t PostSyncOperation : __CODEGEN_BITFIELD(21, 21);  //!< POST_SYNC_OPERATION
                    uint32_t MemoryType : __CODEGEN_BITFIELD(22, 22);         //!< MEMORY_TYPE
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);    //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);        //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t WorkloadPartitionIdOffsetEnable : __CODEGEN_BITFIELD(0, 0);  //!< WORKLOAD_PARTITION_ID_OFFSET_ENABLE
                    uint32_t Reserved33 : __CODEGEN_BITFIELD(1, 1);                       //!< Reserved
                    uint32_t MemoryAddress : __CODEGEN_BITFIELD(2, 31);                   //!< Memory Address
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint32_t MemoryAddressHigh : __CODEGEN_BITFIELD(0, 15);  //!< Memory Address High
                    uint32_t Reserved80 : __CODEGEN_BITFIELD(16, 31);        //!< Reserved
                };
                uint32_t Value;
            } DW2;
            union
            {
                struct
                {
                    uint32_t Operand1DataDword0;  //!< Operand1 Data Dword 0
                };
                uint32_t Value;
            } DW3;
            union
            {
                struct
                {
                    uint32_t Operand2DataDword0;  //!< Operand2 Data Dword 0
                };
                uint32_t Value;
            } DW4;
            union
            {
                struct
                {
                    uint32_t Operand1DataDword1;  //!< Operand1 Data Dword 1
                };
                uint32_t Value;
            } DW5;
            union
            {
                struct
                {
                    uint32_t Operand2DataDword1;  //!< Operand2 Data Dword 1
                };
                uint32_t Value;
            } DW6;
            union
            {
                struct
                {
                    uint32_t Operand1DataDword2;  //!< Operand1 Data Dword 2
                };
                uint32_t Value;
            } DW7;
            union
            {
                struct
                {
                    uint32_t Operand2DataDword2;  //!< Operand2 Data Dword 2
                };
                uint32_t Value;
            } DW8;
            union
            {
                struct
                {
                    uint32_t Operand1DataDword3;  //!< Operand1 Data Dword 3
                };
                uint32_t Value;
            } DW9;
            union
            {
                struct
                {
                    uint32_t Operand2DataDword3;  //!< Operand2 Data Dword 3
                };
                uint32_t Value;
            } DW10;

            //! \name Local enumerations

            //! \brief DATA_SIZE
            //! \details
            //!     This field indicates the size of the operand in dword/qword/octword on
            //!     which atomic operation will be performed. Data size must match with the
            //!     Atomic Opcode. Operation Data size could be 4B, 8B or 16B
            enum DATA_SIZE
            {
                DATA_SIZE_DWORD   = 0,  //!< Operand size used by Atomic Operation is DWORD.
                DATA_SIZE_QWORD   = 1,  //!< Operand Size used by Atomic Operation is QWORD.
                DATA_SIZE_OCTWORD = 2,  //!< Operand Size used by Atomic Operation is OCTWORD.
            };

            //! \brief POST_SYNC_OPERATION
            //! \details
            //!     Any desired pipeline flush operation can be achieved by programming
            //!     PIPE_CONTROL command prior to this command.
            enum POST_SYNC_OPERATION
            {
                POST_SYNC_OPERATION_NOPOSTSYNCOPERATION = 0,  //!< Command is executed as usual.
                POST_SYNC_OPERATION_POSTSYNCOPERATION   = 1,  //!< MI_ATOMIC command is executed as a pipelined PIPE_CONTROL flush command with Atomics operation as post sync operation. Flush completion only guarantees the workload prior to this command is pushed till Windower unit and completion of any outstanding flushes issued prior to this command.When this bit set following restiriciton apply to atomic operation:Non-Compare atomic operations are supported on data granularity of 4B and 8B. DW3 is the lower dword of the operand and DW4 is the upper dword of the operand for the atomic operation.Compare atomic operations are supported on data granularity of 4B. DW3 is Operand-0 and DW4 is Operand-1 for the atomic operation.Atomic operations to GGTT/PPGTT memory surface are supported.Only Inline data mode for atomic operand is supported, no support for indirect data mode.No support for Return Data Control functionality.No support for atomic operations on data granularity of 16B.No support for compare atomic operations on data granularity of 8B.
            };

            //! \brief MEMORY_TYPE
            //! \details
            //!     This bit will be ignored and treated as if clear when executing from a
            //!     non-privileged batch buffer. It is allowed for this bit to be clear when
            //!     executing this command from a privileged (secure) batch buffer. This bit
            //!     must be 1 if the Per Process GTT Enable bit is clear.
            enum MEMORY_TYPE
            {
                MEMORY_TYPE_PERPROCESSGRAPHICSADDRESS = 0,  //!< No additional details
                MEMORY_TYPE_GLOBALGRAPHICSADDRESS     = 1,  //!< This command will use the global GTT to translate the Address and this command must be executing from a privileged (secure) batch buffer.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIATOMIC = 47,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \brief WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            //! \details
            //!     This bit controls the memory write address computation for the atomic operation.
            //!     The final memory write address is computed by adding the Workload PartitionID
            //!     times the Address Offset to the memory address mentioned in the command.
            //!
            //!      Workload Partition ID gets programmed through
            //!     WPARIDregister and the Address Offset gets programmed through
            //!     CS_MI_ADDRESS_OFFSET register..
            //!      Example: Final Memory Write Address[47:2] = (Workload Partition ID
            //!      * "Address Offset") + Memory Write Address [47:2]
            enum WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            {
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0 = 0,  //!< There is no offset added to the memory write address.
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED1 = 1,  //!< The final memory address is computed based on the Workload Partition ID
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_ATOMIC_CMD()
            {
                DW0.Value = 0x17800009;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.AtomicOpcode                                 = 0;
                //DW0.DataSize                                     = DATA_SIZE_DWORD;
                //DW0.PostSyncOperation                            = POST_SYNC_OPERATION_NOPOSTSYNCOPERATION;
                //DW0.MemoryType                                   = MEMORY_TYPE_PERPROCESSGRAPHICSADDRESS;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIATOMIC;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;
                //DW1.WorkloadPartitionIdOffsetEnable              = WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0;

                DW2.Value = 0x00000000;

                DW3.Value = 0x00000000;

                DW4.Value = 0x00000000;

                DW5.Value = 0x00000000;

                DW6.Value = 0x00000000;

                DW7.Value = 0x00000000;

                DW8.Value = 0x00000000;

                DW9.Value = 0x00000000;

                DW10.Value = 0x00000000;
            }

            static const size_t dwSize   = 11;
            static const size_t byteSize = 44;
        };
        //!
        //! \brief MI_MATH
        //! \details
        //!     The MI_MATH command allows SW to send instruction to ALU in Any Command
        //!     Streamer.
        //!     MI_MATH command is the means by which ALU can be accessed. ALU
        //!     instructions form the data payload of MI_MATH command, ALU instruction
        //!     is dword in size. MI_MATH Dword Length should be programmed based on the
        //!     number of ALU instruction packed, max number is limited by the max Dword
        //!     Length supported. When MI_MATH command is parsed by command streamer it
        //!     outputs the payload dwords (ALU instructions) to the ALU. ALU takes
        //!     single clock to process any given instruction. Refer to "Command
        //!     Streamer (CS) ALU Programming" section in Command Streamer Programming.
        //!
        struct MI_MATH_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                //!< DWord Length
                    uint32_t MemoryObjectControlState : __CODEGEN_BITFIELD(8, 14);  //!< Memory Object Control State
                    uint32_t PredicationEnable : __CODEGEN_BITFIELD(15, 15);        //!< Predication Enable
                    uint32_t Reserved16 : __CODEGEN_BITFIELD(16, 22);               //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);          //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);              //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;

            //! \name Local enumerations

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIMATH = 26,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_MATH_CMD()
            {
                DW0.Value = 0x0d000000;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIMATH;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;
            }

            static const size_t dwSize   = 1;
            static const size_t byteSize = 4;
        };

        //!
        //! \brief MI_FLUSH_DW
        //! \details
        //!     The MI_FLUSH_DW command is used to perform an internal "flush"
        //!     operation. The parser pauses on an internal flush until all drawing
        //!     engines have completed any pending operations. In addition, this command
        //!     can also be used to:Flush any dirty data to memory. Invalidate the TLB
        //!     cache inside the hardware Usage note: After this command is completed
        //!     with a Store DWord enabled, CPU access to graphics memory will be
        //!     coherent (assuming the Render Cache flush is not inhibited).
        //!
        struct MI_FLUSH_DW_CMD
        {
            union
            {
                //!< DWORD 0
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 5);                   //!< DWORD_LENGTH
                    uint32_t Reserved6 : __CODEGEN_BITFIELD(6, 6);                     //!< Reserved
                    uint32_t VideoPipelineCacheInvalidate : __CODEGEN_BITFIELD(7, 7);  //!< Video Pipeline Cache invalidate
                    uint32_t NotifyEnable : __CODEGEN_BITFIELD(8, 8);                  //!< Notify Enable
                    uint32_t FlushLlc : __CODEGEN_BITFIELD(9, 9);                      //!< Flush LLC
                    uint32_t Reserved10 : __CODEGEN_BITFIELD(10, 13);                  //!< Reserved
                    uint32_t PostSyncOperation : __CODEGEN_BITFIELD(14, 15);           //!< POST_SYNC_OPERATION
                    uint32_t FlushCcs : __CODEGEN_BITFIELD(16, 16);                    //!< Flush CCS
                    uint32_t Reserved17 : __CODEGEN_BITFIELD(17, 17);                  //!< Reserved
                    uint32_t TlbInvalidate : __CODEGEN_BITFIELD(18, 18);               //!< TLB Invalidate
                    uint32_t FlushPpc : __CODEGEN_BITFIELD(19, 19);                    //!< Flush PPC
                    uint32_t Reserved20 : __CODEGEN_BITFIELD(20, 20);                  //!< Reserved
                    uint32_t StoreDataIndex : __CODEGEN_BITFIELD(21, 21);              //!< Store Data Index
                    uint32_t Reserved22 : __CODEGEN_BITFIELD(22, 22);                  //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);             //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                 //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                //!< DWORD 1..2
                struct
                {
                uint64_t                 Reserved32                                       : __CODEGEN_BITFIELD( 0,  1)    ; //!< Reserved
                uint64_t                 DestinationAddressType                           : __CODEGEN_BITFIELD( 2,  2)    ; //!< DESTINATION_ADDRESS_TYPE
                uint64_t                 DestinationAddress                               : __CODEGEN_BITFIELD( 3, 47)    ; //!< Destination Address
                uint64_t                 Reserved80                                       : __CODEGEN_BITFIELD(48, 63)    ; //!< Reserved
                };
                uint32_t Value[2];
            } DW1_2;
            union
            {
                //!< DWORD 3..4
                struct
                {
                    uint64_t ImmediateData;  //!< Immediate Data
                };
                uint32_t Value[2];
            } DW3_4;

            //! \name Local enumerations

            //! \brief POST_SYNC_OPERATION
            //! \details
            //!     BitFieldDesc
            enum POST_SYNC_OPERATION
            {
                POST_SYNC_OPERATION_NOWRITE            = 0,  //!< No write occurs as a result of this instruction. This can be used to implement a "trap" operation, etc.
                POST_SYNC_OPERATION_WRITEIMMEDIATEDATA = 1,  //!< HW implicitly detects the Data size to be Qword or Dword to be written to memory based on the command dword length programmed  . When Dword Length indicates Qword, Writes the QWord containing Immediate Data Low, High DWs to the Destination Address . When Dword Length indicates Dword, Writes the DWord containing Immediate Data Low to the Destination Address
                POST_SYNC_OPERATION_UNNAMED3           = 3,  //!< Write the TIMESTAMP register to the Destination Address. The upper 28 bits of the TIMESTAMP register are tied to '0'.
            };

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIFLUSHDW = 38,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \brief DESTINATION_ADDRESS_TYPE
            //! \details
            //!     Defines address space of Destination Address
            enum DESTINATION_ADDRESS_TYPE
            {
                DESTINATION_ADDRESS_TYPE_PPGTT = 0,  //!< Use PPGTT address space for DW write
                DESTINATION_ADDRESS_TYPE_GGTT  = 1,  //!< Use GGTT address space for DW write
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_FLUSH_DW_CMD()
            {
                DW0.Value = 0x13000003;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.PostSyncOperation                            = POST_SYNC_OPERATION_NOWRITE;
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIFLUSHDW;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1_2.Value[0] = DW1_2.Value[1] = 0;
                DW1_2.DestinationAddressType = DESTINATION_ADDRESS_TYPE_PPGTT;

                DW3_4.Value[0] = DW3_4.Value[1] = 0x00000000;
            }

            static const size_t dwSize   = 5;
            static const size_t byteSize = 20;
        };

        //!
        //! \brief MI_FORCE_WAKEUP
        //! \details
        //!     This command is used to communicate Force Wakeup request to PM unit. No
        //!     functionality is performed by this command when none of the mask bits
        //!     are set and is equivalent to NOOP. Example for usage model: VCS Ring
        //!     Buffer: MI_FORCE_WAKEUP (Force Render Awake set to '1')
        //!     MI_SEMPAHORE_SIGNAL (Signal context id 0xABC to Render Command Streamer)
        //!     MI_FORCE_WAKEUP (Force Render Awake set to '0') MI_BATCH_BUFFER_START
        //!     STATE Commands .. .. MI_FORCE_WAKEUP (Force Render Awake set to '1')
        //!     MI_LOAD_REGISTER_IMMEDIATE (Load register 0x23XX in render command
        //!     streamer with data 0xFFF) MI_FORCE_WAKEUP (Force Render Awake set to
        //!     '0') .. MI_BATCH_BUFFER_END
        //!
        //!     This command must not be programmed in the command stream for Render
        //!     Engine Command Streamer or Position Commmand Streamer or Compute Engine
        //!     Command Streamer.
        //!
        struct MI_FORCE_WAKEUP_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);        //!< DWORD_LENGTH
                    uint32_t Reserved8 : __CODEGEN_BITFIELD(8, 22);         //!< Reserved
                    uint32_t MiCommandOpcode : __CODEGEN_BITFIELD(23, 28);  //!< MI_COMMAND_OPCODE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);      //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t ForceMediaSlice0Awake : __CODEGEN_BITFIELD(0, 0);  //!< Force Media-Slice0 Awake
                    uint32_t ForceRenderAwake : __CODEGEN_BITFIELD(1, 1);       //!< Force Render Awake
                    uint32_t ForceMediaSlice1Awake : __CODEGEN_BITFIELD(2, 2);  //!< Force Media-Slice1 Awake
                    uint32_t ForceMediaSlice2Awake : __CODEGEN_BITFIELD(3, 3);  //!< Force Media-Slice2 Awake
                    uint32_t ForceMediaSlice3Awake : __CODEGEN_BITFIELD(4, 4);  //!< Force Media-Slice3 Awake
                    uint32_t Reserved37 : __CODEGEN_BITFIELD(5, 7);             //!< Reserved
                    uint32_t HevcPowerWellControl : __CODEGEN_BITFIELD(8, 8);   //!< HEVC_POWER_WELL_CONTROL
                    uint32_t MfxPowerWellControl : __CODEGEN_BITFIELD(9, 9);    //!< MFX_POWER_WELL_CONTROL
                    uint32_t Reserved42 : __CODEGEN_BITFIELD(10, 15);           //!< Reserved
                    uint32_t MaskBits : __CODEGEN_BITFIELD(16, 31);             //!< Mask Bits
                };
                uint32_t Value;
            } DW1;

            //! \name Local enumerations

            enum MI_COMMAND_OPCODE
            {
                MI_COMMAND_OPCODE_MIFORCEWAKEUP = 29,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_MICOMMAND = 0,  //!< No additional details
            };

            //! \brief HEVC_POWER_WELL_CONTROL
            //! \details
            //!     This Bit controls whether or not the HEVC Power Well is powered.  When
            //!     this bit is unmasked, all force awake bits programming are ignored.
            enum HEVC_POWER_WELL_CONTROL
            {
                HEVC_POWER_WELL_CONTROL_DISABLEPOWERWELL = 0,  //!< No additional details
                HEVC_POWER_WELL_CONTROL_ENABLEPOWERWELL  = 1,  //!< No additional details
            };

            //! \brief MFX_POWER_WELL_CONTROL
            //! \details
            //!     This Bit controls whether or not the MFX Power Well is powered.  When
            //!     this bit is unmasked, all force awake bits programming are ignored.
            enum MFX_POWER_WELL_CONTROL
            {
                MFX_POWER_WELL_CONTROL_DISABLEPOWERWELL = 0,  //!< No additional details
                MFX_POWER_WELL_CONTROL_ENABLEPOWERWELL  = 1,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MI_FORCE_WAKEUP_CMD()
            {
                DW0.Value = 0x0e800000;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIFORCEWAKEUP;
                //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;

                DW1.Value = 0x00000000;
                //DW1.HevcPowerWellControl                         = HEVC_POWER_WELL_CONTROL_DISABLEPOWERWELL;
                //DW1.MfxPowerWellControl                          = MFX_POWER_WELL_CONTROL_DISABLEPOWERWELL;
            }

            static const size_t dwSize   = 2;
            static const size_t byteSize = 8;
        };

        //!
        //! \brief PIPE_CONTROL
        //! \details
        //!     The PIPE_CONTROL command is used to effect the synchronization described
        //!     above.
        //!
        //!     SW must follow below programming restrictions when programming
        //!     PIPE_CONTROL command for ComputeCS:
        //!       "Command Streamer Stall Enable" must be always set.
        //!     Post Sync Operations must not be set to Write PS Depth Count
        //!     Following bits must not be set when programmed for ComputeCS"Render
        //!     Target Cache Flush Enable", "Depth Cache Flush Enable" and "Tile Cache
        //!     Flush Enable"
        //!     "Depth Stall Enable", Stall at Pixel Scoreboard and "PSD Sync Enable".
        //!     "OVR Tile 0 Flush", "TBIMR Force Batch Closure", "AMFS Flush Enable" "VF
        //!     Cache Invalidation Enable" and "Global Snapshot Count Reset".
        //!
        struct PIPE_CONTROL_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 7);                          //!< DWORD_LENGTH
                    uint32_t PredicateEnable : __CODEGEN_BITFIELD(8, 8);                      //!< Predicate Enable
                    uint32_t DataportFlush : __CODEGEN_BITFIELD(9, 9);                        //!< Dataport Flush
                    uint32_t L3ReadOnlyCacheInvalidationEnable : __CODEGEN_BITFIELD(10, 10);  //!< L3 Read Only Cache Invalidation Enable
                    uint32_t UnTypedDataPortCacheFlush : __CODEGEN_BITFIELD(11, 11);          //!< Un-Typed Data-Port Cache Flush
                    uint32_t Reserved12 : __CODEGEN_BITFIELD(12, 12);                         //!< Reserved
                    uint32_t CompressionControlSurfaceCcsFlush : __CODEGEN_BITFIELD(13, 13);  //!< Compression Control Surface (CCS) Flush
                    uint32_t WorkloadPartitionIdOffsetEnable : __CODEGEN_BITFIELD(14, 14);    //!< WORKLOAD_PARTITION_ID_OFFSET_ENABLE
                    uint32_t Reserved15 : __CODEGEN_BITFIELD(15, 15);                         //!< Reserved
                    uint32_t _3DCommandSubOpcode : __CODEGEN_BITFIELD(16, 23);                //!< _3D_COMMAND_SUB_OPCODE
                    uint32_t _3DCommandOpcode : __CODEGEN_BITFIELD(24, 26);                   //!< _3D_COMMAND_OPCODE
                    uint32_t CommandSubtype : __CODEGEN_BITFIELD(27, 28);                     //!< COMMAND_SUBTYPE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);                        //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t DepthCacheFlushEnable : __CODEGEN_BITFIELD(0, 0);               //!< DEPTH_CACHE_FLUSH_ENABLE
                    uint32_t StallAtPixelScoreboard : __CODEGEN_BITFIELD(1, 1);              //!< STALL_AT_PIXEL_SCOREBOARD
                    uint32_t StateCacheInvalidationEnable : __CODEGEN_BITFIELD(2, 2);        //!< State Cache Invalidation Enable
                    uint32_t ConstantCacheInvalidationEnable : __CODEGEN_BITFIELD(3, 3);     //!< Constant Cache Invalidation Enable
                    uint32_t VfCacheInvalidationEnable : __CODEGEN_BITFIELD(4, 4);           //!< VF Cache Invalidation Enable
                    uint32_t DcFlushEnable : __CODEGEN_BITFIELD(5, 5);                       //!< DC  Flush Enable
                    uint32_t Reserved38 : __CODEGEN_BITFIELD(6, 6);                          //!< Reserved
                    uint32_t PipeControlFlushEnable : __CODEGEN_BITFIELD(7, 7);              //!< Pipe Control Flush Enable
                    uint32_t NotifyEnable : __CODEGEN_BITFIELD(8, 8);                        //!< Notify Enable
                    uint32_t IndirectStatePointersDisable : __CODEGEN_BITFIELD(9, 9);        //!< Indirect State Pointers Disable
                    uint32_t TextureCacheInvalidationEnable : __CODEGEN_BITFIELD(10, 10);    //!< Texture Cache Invalidation Enable
                    uint32_t InstructionCacheInvalidateEnable : __CODEGEN_BITFIELD(11, 11);  //!< Instruction Cache Invalidate Enable
                    uint32_t RenderTargetCacheFlushEnable : __CODEGEN_BITFIELD(12, 12);      //!< RENDER_TARGET_CACHE_FLUSH_ENABLE
                    uint32_t DepthStallEnable : __CODEGEN_BITFIELD(13, 13);                  //!< DEPTH_STALL_ENABLE
                    uint32_t PostSyncOperation : __CODEGEN_BITFIELD(14, 15);                 //!< POST_SYNC_OPERATION
                    uint32_t GenericMediaStateClear : __CODEGEN_BITFIELD(16, 16);            //!< Generic Media State Clear
                    uint32_t PssStallSyncEnable : __CODEGEN_BITFIELD(17, 17);                //!< PSS Stall Sync Enable
                    uint32_t TlbInvalidate : __CODEGEN_BITFIELD(18, 18);                     //!< TLB Invalidate
                    uint32_t DepthStallSyncEnable : __CODEGEN_BITFIELD(19, 19);              //!< Depth Stall Sync Enable
                    uint32_t CommandStreamerStallEnable : __CODEGEN_BITFIELD(20, 20);        //!< Command Streamer Stall Enable
                    uint32_t StoreDataIndex : __CODEGEN_BITFIELD(21, 21);                    //!< Store Data Index
                    uint32_t Reserved54 : __CODEGEN_BITFIELD(22, 22);                        //!< Reserved
                    uint32_t LriPostSyncOperation : __CODEGEN_BITFIELD(23, 23);              //!< LRI_POST_SYNC_OPERATION
                    uint32_t DestinationAddressType : __CODEGEN_BITFIELD(24, 24);            //!< DESTINATION_ADDRESS_TYPE
                    uint32_t AmfsFlushEnable : __CODEGEN_BITFIELD(25, 25);                   //!< AMFS Flush Enable
                    uint32_t FlushLlc : __CODEGEN_BITFIELD(26, 26);                          //!< Flush LLC
                    uint32_t Reserved59 : __CODEGEN_BITFIELD(27, 27);                        //!< Reserved
                    uint32_t TileCacheFlushEnable : __CODEGEN_BITFIELD(28, 28);              //!< TILE_CACHE_FLUSH_ENABLE
                    uint32_t CommandCacheInvalidateEnable : __CODEGEN_BITFIELD(29, 29);      //!< Command Cache Invalidate Enable
                    uint32_t L3FabricFlush : __CODEGEN_BITFIELD(30, 30);                     //!< L3_FABRIC_FLUSH
                    uint32_t TbimrForceBatchClosure : __CODEGEN_BITFIELD(31, 31);            //!< TBIMR_FORCE_BATCH_CLOSURE
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint32_t Reserved64 : __CODEGEN_BITFIELD(0, 1);  //!< Reserved
                    uint32_t Address : __CODEGEN_BITFIELD(2, 31);    //!< Address
                };
                uint32_t Value;
            } DW2;
            union
            {
                struct
                {
                    uint32_t AddressHigh;  //!< Address High
                };
                uint32_t Value;
            } DW3;
            union
            {
                struct
                {
                    uint64_t ImmediateData;  //!< Immediate Data
                };
                uint32_t Value[2];
            } DW4_5;

            //! \name Local enumerations

            //! \brief WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            //! \details
            //!     This bit controls the memory write address computation for the store data update.
            //!     The final memory write address is computed by adding the Workload
            //!     Partition ID times the Address Offset to the memory address mentioned in the command.
            //!     Workload Partition ID gets programmed through
            //!     WPARIDregister and the Address Offset gets programmed through
            //!     CS_MI_ADDRESS_OFFSET register..
            //!     Example: Final Memory Write Address[47:2] = ( Workload Partition ID * "Address Offset")
            //!     + Memory Write Address [47:2]
            enum WORKLOAD_PARTITION_ID_OFFSET_ENABLE
            {
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0 = 0,  //!<   There is no offset added to the memory write address.
                WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED1 = 1,  //!<   The final memory address is computed based on the Workload Partition ID
            };

            enum _3D_COMMAND_SUB_OPCODE
            {
                _3D_COMMAND_SUB_OPCODE_PIPECONTROL = 0,  //!< No additional details
            };

            enum _3D_COMMAND_OPCODE
            {
                _3D_COMMAND_OPCODE_PIPECONTROL = 2,  //!< No additional details
            };

            enum COMMAND_SUBTYPE
            {
                COMMAND_SUBTYPE_GFXPIPE3D = 3,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_GFXPIPE = 3,  //!< No additional details
            };

            //! \brief DEPTH_CACHE_FLUSH_ENABLE
            //! \details
            //!     Setting this bit enables flushing (i.e. writing back the dirty lines to
            //!     memory and invalidating the tags) of depth related caches. This bit
            //!     applies to HiZ cache, Stencil cache and depth cache.
            enum DEPTH_CACHE_FLUSH_ENABLE
            {
                DEPTH_CACHE_FLUSH_ENABLE_FLUSHDISABLED = 0,  //!< Depth relates caches (HiZ, Stencil and Depth) are NOT flushed.
                DEPTH_CACHE_FLUSH_ENABLE_FLUSHENABLED  = 1,  //!< Depth relates caches (HiZ, Stencil and Depth) are flushed.
            };

            //! \brief STALL_AT_PIXEL_SCOREBOARD
            //! \details
            //!     Defines the behavior of PIPE_CONTROL command at the pixel scoreboard.
            enum STALL_AT_PIXEL_SCOREBOARD
            {
                STALL_AT_PIXEL_SCOREBOARD_DISABLE = 0,  //!< Stall at the pixel scoreboard is disabled.
                STALL_AT_PIXEL_SCOREBOARD_ENABLE  = 1,  //!< Stall at the pixel scoreboard is enabled.
            };

            //! \brief RENDER_TARGET_CACHE_FLUSH_ENABLE
            //! \details
            //!     Setting this bit will force Render Cache to be flushed to memory
            //!     prior to this synchronization point completing. This bit must be set for
            //!     all write fence sync operations to assure that results from operations
            //!     initiated prior to this command are visible in memory once software
            //!     observes this synchronization.
            enum RENDER_TARGET_CACHE_FLUSH_ENABLE
            {
                RENDER_TARGET_CACHE_FLUSH_ENABLE_DISABLEFLUSH = 0,  //!< Render Target Cache is NOT flushed.
                RENDER_TARGET_CACHE_FLUSH_ENABLE_ENABLEFLUSH  = 1,  //!< Render Target Cache is flushed.
            };

            //! \brief DEPTH_STALL_ENABLE
            //! \details
            //!     This bit must be set when obtaining a "visible pixel" count to
            //!     preclude the possible inclusion in the PS_DEPTH_COUNT value written to
            //!     memory of some fraction of pixels from objects initiated after the
            //!     PIPE_CONTROL command.
            enum DEPTH_STALL_ENABLE
            {
                DEPTH_STALL_ENABLE_DISABLE = 0,  //!< 3D pipeline will not stall subsequent primitives at the Depth Test stage.
                DEPTH_STALL_ENABLE_ENABLE  = 1,  //!< 3D pipeline will stall any subsequent primitives at the Depth Test stage until the Sync and Post-Sync operations complete.
            };

            //! \brief POST_SYNC_OPERATION
            //! \details
            //!     This field specifies an optional action to be taken upon completion of
            //!     the synchronization operation.
            enum POST_SYNC_OPERATION
            {
                POST_SYNC_OPERATION_NOWRITE            = 0,  //!< No write occurs as a result of this instruction. This can be used to implement a "trap" operation, etc.
                POST_SYNC_OPERATION_WRITEIMMEDIATEDATA = 1,  //!< Write the QWord containing Immediate Data Low, High DWs to the Destination Address
                POST_SYNC_OPERATION_WRITEPSDEPTHCOUNT  = 2,  //!< Write the 64-bit PS_DEPTH_COUNT register to the Destination Address
                POST_SYNC_OPERATION_WRITETIMESTAMP     = 3,  //!< Write the 64-bit TIMESTAMP register(i.e. "Reported Timestamp Count" 0x2358 for render pipe) to the Destination Address.
            };

            //! \brief LRI_POST_SYNC_OPERATION
            //! \details
            //!     This bit caues a post sync operation with an LRI (Load Register
            //!     Immediate) operation. If this bit is set then the Post-Sync Operation
            //!     field must be cleared.
            enum LRI_POST_SYNC_OPERATION
            {
                LRI_POST_SYNC_OPERATION_NOLRIOPERATION         = 0,  //!< No LRI operation occurs as a result of this instruction. The Post-Sync Operation field is valid and may be used to specify an operation.
                LRI_POST_SYNC_OPERATION_MMIOWRITEIMMEDIATEDATA = 1,  //!< Write the DWord contained in Immediate Data Low (DW3) to the MMIO offset specified in the Address field.
            };

            //! \brief DESTINATION_ADDRESS_TYPE
            //! \details
            //!     Defines address space of Destination Address
            enum DESTINATION_ADDRESS_TYPE
            {
                DESTINATION_ADDRESS_TYPE_PPGTT = 0,  //!< Use PPGTT address space for DW write
                DESTINATION_ADDRESS_TYPE_GGTT  = 1,  //!< Use GGTT address space for DW write
            };

            //! \brief TILE_CACHE_FLUSH_ENABLE
            //! \details
            //!     Setting this bit will force Tile Cache (contains both color and depth
            //!     data) to be flushed to memory prior to this synchronization point
            //!     completing. This bit must be set for all write fence sync operations to
            //!     assure that results from operations initiated prior to this command are
            //!     visible in memory once software observes this synchronization.
            //!       />
            enum TILE_CACHE_FLUSH_ENABLE
            {
                TILE_CACHE_FLUSH_ENABLE_UNNAMED0 = 0,  //!< Tile Cache is not flushed.
                TILE_CACHE_FLUSH_ENABLE_UNNAMED1 = 1,  //!< Tile cache is flushed.
            };

            //! \brief L3_FABRIC_FLUSH
            //! \details
            //!     L3 Fabric Flush will ensure all the pending transactions in the L3
            //!     Fabric are flushed to global observation point. HW does implicit L3
            //!     Fabric Flush on all stalling flushes (both explicit and implicit) and on
            //!     PIPECONTROL having Post Sync Operation enabled. This bit provides an
            //!     explicit control for debug purpose.
            //!       />
            enum L3_FABRIC_FLUSH
            {
                L3_FABRIC_FLUSH_UNNAMED0 = 0,  //!< HW will not force a "L3 Fabric Flush" on completion of flush and will only do on need basis.
                L3_FABRIC_FLUSH_UNNAMED1 = 1,  //!< HW will do a L3 Fabric Flush on completion of flush for the corresponding PIPECONTROL. Setting this bit will force HW to send a marker downstream for a flush completion.
            };

            //! \brief TBIMR_FORCE_BATCH_CLOSURE
            //! \details
            //!     This bit forces SF to close the batch. This bit must be set with a post
            //!     sync operation.
            enum TBIMR_FORCE_BATCH_CLOSURE
            {
                TBIMR_FORCE_BATCH_CLOSURE_NOBATCHCLOSURE = 0,  //!< SF will not close the batch on receiving marker.
                TBIMR_FORCE_BATCH_CLOSURE_CLOSEBATCH     = 1,  //!< SF will close the batch on receiving the marker associated with this command.
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            PIPE_CONTROL_CMD()
            {
                DW0.Value = 0x7a000004;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.WorkloadPartitionIdOffsetEnable              = WORKLOAD_PARTITION_ID_OFFSET_ENABLE_UNNAMED0;
                //DW0._3DCommandSubOpcode                          = _3D_COMMAND_SUB_OPCODE_PIPECONTROL;
                //DW0._3DCommandOpcode                             = _3D_COMMAND_OPCODE_PIPECONTROL;
                //DW0.CommandSubtype                               = COMMAND_SUBTYPE_GFXPIPE3D;
                //DW0.CommandType                                  = COMMAND_TYPE_GFXPIPE;

                DW1.Value = 0x00000000;
                //DW1.DepthCacheFlushEnable                        = DEPTH_CACHE_FLUSH_ENABLE_FLUSHDISABLED;
                //DW1.StallAtPixelScoreboard                       = STALL_AT_PIXEL_SCOREBOARD_DISABLE;
                //DW1.RenderTargetCacheFlushEnable                 = RENDER_TARGET_CACHE_FLUSH_ENABLE_DISABLEFLUSH;
                //DW1.DepthStallEnable                             = DEPTH_STALL_ENABLE_DISABLE;
                //DW1.PostSyncOperation                            = POST_SYNC_OPERATION_NOWRITE;
                //DW1.LriPostSyncOperation                         = LRI_POST_SYNC_OPERATION_NOLRIOPERATION;
                //DW1.DestinationAddressType                       = DESTINATION_ADDRESS_TYPE_PPGTT;
                //DW1.TbimrForceBatchClosure                       = TBIMR_FORCE_BATCH_CLOSURE_NOBATCHCLOSURE;

                DW2.Value = 0x00000000;

                DW3.Value = 0x00000000;

                DW4_5.Value[0] = DW4_5.Value[1] = 0x00000000;
            }

            static const size_t dwSize   = 6;
            static const size_t byteSize = 24;
        };

        //!
        //! \brief MFX_WAIT
        //! \details
        //!     This command can be considered the same as an MI_NOOPexcept that the
        //!     command parser will not parse the next command until the
        //!     followinghappens    AVC or VC1 BSD mode: The command will stall the
        //!     parser until completion of theBSD object
        //!       IT, encoder, and MPEG2 BSD mode: The command will stall the parser
        //!     until theobject package is sent down the pipelineThis command should be
        //!     used to ensure thepreemption enable window occurs during the time the
        //!     object command is being executeddown the pipeline.
        //!
        struct MFX_WAIT_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 5);          //!< DWORD_LENGTH
                    uint32_t Reserved6 : __CODEGEN_BITFIELD(6, 7);            //!< Reserved
                    uint32_t MfxSyncControlFlag : __CODEGEN_BITFIELD(8, 8);   //!< MFX Sync Control Flag
                    uint32_t Reserved9 : __CODEGEN_BITFIELD(9, 9);            //!< Reserved
                    uint32_t Reserved10 : __CODEGEN_BITFIELD(10, 15);         //!< Reserved
                    uint32_t SubOpcode : __CODEGEN_BITFIELD(16, 26);          //!< SUB_OPCODE
                    uint32_t CommandSubtype : __CODEGEN_BITFIELD(27, 28);     //!< COMMAND_SUBTYPE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);        //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;

            //! \name Local enumerations

            enum SUB_OPCODE
            {
                SUB_OPCODE_MFXWAIT = 0,  //!< No additional details
            };

            enum COMMAND_SUBTYPE
            {
                COMMAND_SUBTYPE_MFXSINGLEDW = 1,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_PARALLELVIDEOPIPE = 3,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MFX_WAIT_CMD()
            {
                DW0.Value = 0x68000000;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.SubOpcode                                    = SUB_OPCODE_MFXWAIT;
                //DW0.CommandSubtype                               = COMMAND_SUBTYPE_MFXSINGLEDW;
                //DW0.CommandType                                  = COMMAND_TYPE_PARALLELVIDEOPIPE;
            }

            static const size_t dwSize   = 1;
            static const size_t byteSize = 4;
        };

        //!
        //! \brief VD_CONTROL_STATE
        //! \details
        //!     This command can be used in HCPpipe.  For HCP, it is selected with the
        //!     Media Instruction Opcode "7h".   Each command has assigned a media
        //!     instruction command as defined in DWord 0, BitField 22:16. It will be
        //!     different between HCP.
        //!
        //!     This command is used to modify the control of HCP pipe. It can be
        //!     inserted anywhere within a frame. It can be inserted multiple times
        //!     within a frame as well.
        //!
        struct VD_CONTROL_STATE_CMD
        {
            union
            {
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 11);               //!< DWORD_LENGTH
                    uint32_t Reserved12 : __CODEGEN_BITFIELD(12, 15);               //!< Reserved
                    uint32_t MediaInstructionCommand : __CODEGEN_BITFIELD(16, 22);  //!< MEDIA_INSTRUCTION_COMMAND
                    uint32_t MediaInstructionOpcode : __CODEGEN_BITFIELD(23, 26);   //!< MEDIA_INSTRUCTION_OPCODE
                    uint32_t PipelineType : __CODEGEN_BITFIELD(27, 28);             //!< PIPELINE_TYPE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);              //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                struct
                {
                    uint32_t PipelineInitialization : __CODEGEN_BITFIELD(0, 0);                       //!< Pipeline Initialization
                    uint32_t VdboxPipelineArchitectureClockgateDisable : __CODEGEN_BITFIELD(1, 1);    //!< VDBOX_PIPELINE_ARCHITECTURE_CLOCKGATE_DISABLE
                    uint32_t Reserved1 : __CODEGEN_BITFIELD(2, 27);                                   //!< Reserved
                    uint32_t MfxDopClockgateControlWithEnableAsDefault : __CODEGEN_BITFIELD(28, 28);  //!< MFX_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT
                    uint32_t HcpDopClockgateControlWithEnableAsDefault : __CODEGEN_BITFIELD(29, 29);  //!< HCP_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT
                    uint32_t Reserved30 : __CODEGEN_BITFIELD(30, 31);                                 //!< Reserved
                };
                uint32_t Value;
            } DW1;
            union
            {
                struct
                {
                    uint32_t ScalableModePipeLock : __CODEGEN_BITFIELD(0, 0);    //!< Scalable Mode Pipe Lock
                    uint32_t ScalableModePipeUnlock : __CODEGEN_BITFIELD(1, 1);  //!< Scalable Mode Pipe Unlock
                    uint32_t MemoryImplicitFlush : __CODEGEN_BITFIELD(2, 2);     //!< Memory Implicit Flush
                    uint32_t Reserved35 : __CODEGEN_BITFIELD(3, 31);             //!< Reserved
                };
                uint32_t Value;
            } DW2;

            //! \name Local enumerations

            enum MEDIA_INSTRUCTION_COMMAND
            {
                MEDIA_INSTRUCTION_COMMAND_VDCONTROLSTATEFORHCP   = 10,  //!< No additional details
                MEDIA_INSTRUCTION_COMMAND_VDCONTROLSTATEFORVDENC = 11,  //!< No additional details
            };

            //! \brief MEDIA_INSTRUCTION_OPCODE
            //! \details
            //!     Codec/Engine Name = HCP = 7h
            enum MEDIA_INSTRUCTION_OPCODE
            {
                MEDIA_INSTRUCTION_OPCODE_CODECENGINENAMEFORVDENC = 1,  //!< No additional details
                MEDIA_INSTRUCTION_OPCODE_CODECENGINENAMEFORAVP   = 3,  //!< No additional details
                MEDIA_INSTRUCTION_OPCODE_CODECENGINENAMEFORHCP   = 7,  //!< No additional details
            };

            enum PIPELINE_TYPE
            {
                PIPELINE_TYPE_UNNAMED2 = 2,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_PARALLELVIDEOPIPE = 3,  //!< No additional details
            };

            //! \name Local enumerations

            //! \brief MFX_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT
            //! \details
            //!     This bit control the DOP clockgate for MFX pipe. When this bit is set
            //!     to "0", the MFX DOP clockgate is enabled. MFX DOP clockgate is disabled
            //!     when this bit is set to "1"
            enum MFX_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT
            {
                MFX_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT_ENABLE  = 0,  //!< No additional details
                MFX_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT_DISABLE = 1,  //!< No additional details
            };

            //! \brief HCP_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT
            //! \details
            //!     This bit control the DOP clockgate for HCP pipe. When this bit is set
            //!     to "0", the HCP DOP clockgate is enabled. HCP DOP clockgate is disabled
            //!     when this bit is set to "1"
            enum HCP_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT
            {
                HCP_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT_ENABLE  = 0,  //!< No additional details
                HCP_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT_DISABLE = 1,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            VD_CONTROL_STATE_CMD()
            {
                DW0.Value = 0x738a0001;
                //DW0.DwordLength                                  = GetOpLength(dwSize);
                //DW0.MediaInstructionCommand                      = MEDIA_INSTRUCTION_COMMAND_VDCONTROLSTATE;
                //DW0.MediaInstructionOpcode                       = MEDIA_INSTRUCTION_OPCODE_CODECENGINENAMEFORHCP;
                //DW0.PipelineType                                 = PIPELINE_TYPE_UNNAMED2;
                //DW0.CommandType                                  = COMMAND_TYPE_PARALLELVIDEOPIPE;

                DW1.Value = 0x00000000;
                //DW0.MfxDopClockgateControlWithEnableAsDefault    = MFX_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT_ENABLE;
                //DW0.HcpDopClockgateControlWithEnableAsDefault    = HCP_DOP_CLOCKGATE_CONTROL_WITH_ENABLE_AS_DEFAULT_ENABLE;

                DW2.Value = 0x00000000;
            }

            static const size_t dwSize   = 3;
            static const size_t byteSize = 12;
        };

        //!
//! \brief MEDIA_STATE_FLUSH
//! \details
//!     This command updates the Message Gateway state. In particular, it
//!     updates the state for a selected Interface Descriptor.
//!
//!     This command can be considered same as a MI_Flush except that only media
//!     parser will get flushed instead of the entire 3D/media render pipeline.
//!     The command should be programmed prior to new Media state, curbe and/or
//!     interface descriptor commands when switching to a new context or
//!     programming new state for the same context. With this command, pipelined
//!     state change is allowed for the media pipe.
//!
//!     Be cautious when using this command when child_present flag in the media
//!     state is enabled. This is because that CURBE state as well as Interface
//!     Descriptor state are shared between root threads and child threads.
//!     Changing these states while child threads are generated on the fly may
//!     cause unexpected behavior. Combining with MI_ARB_ON/OFF command, it is
//!     possible to support interruptability with the following command sequence
//!     where interrupt may be allowed only when MI_ARB_ON_OFF is ON:
//!
//!     <pre>MEDIA_STATE_FLUSH
//!     VFE_STATE  VFE will hold CS if watermark isn't met
//!     MI_ARB_OFF  There must be at least one VFE command before this one
//!     MEDIA_OBJECT ... MI_ARB_ON</pre>
//!
        struct MEDIA_STATE_FLUSH_CMD
        {
            union
            {
                //!< DWORD 0
                struct
                {
                    uint32_t DwordLength : __CODEGEN_BITFIELD(0, 15);          //!< DWORD_LENGTH
                    uint32_t Subopcode : __CODEGEN_BITFIELD(16, 23);           //!< SUBOPCODE
                    uint32_t MediaCommandOpcode : __CODEGEN_BITFIELD(24, 26);  //!< MEDIA_COMMAND_OPCODE
                    uint32_t Pipeline : __CODEGEN_BITFIELD(27, 28);            //!< PIPELINE
                    uint32_t CommandType : __CODEGEN_BITFIELD(29, 31);         //!< COMMAND_TYPE
                };
                uint32_t Value;
            } DW0;
            union
            {
                //!< DWORD 1
                struct
                {
                    uint32_t InterfaceDescriptorOffset : __CODEGEN_BITFIELD(0, 5);  //!< Interface Descriptor Offset
                    uint32_t Reserved38 : __CODEGEN_BITFIELD(6, 6);                 //!< Reserved
                    uint32_t FlushToGo : __CODEGEN_BITFIELD(7, 7);                  //!< Flush to GO
                    uint32_t Reserved40 : __CODEGEN_BITFIELD(8, 31);                //!< Reserved
                };
                uint32_t Value;
            } DW1;

            //! \name Local enumerations

            enum SUBOPCODE
            {
                SUBOPCODE_MEDIASTATEFLUSHSUBOP = 4,  //!< No additional details
            };

            enum MEDIA_COMMAND_OPCODE
            {
                MEDIA_COMMAND_OPCODE_MEDIASTATEFLUSH = 0,  //!< No additional details
            };

            enum PIPELINE
            {
                PIPELINE_MEDIA = 2,  //!< No additional details
            };

            enum COMMAND_TYPE
            {
                COMMAND_TYPE_GFXPIPE = 3,  //!< No additional details
            };

            //! \name Initializations

            //! \brief Explicit member initialization function
            MEDIA_STATE_FLUSH_CMD()
            {
                DW0.Value = 0;
                DW0.DwordLength = GetOpLength(dwSize);
                DW0.Subopcode = SUBOPCODE_MEDIASTATEFLUSHSUBOP;
                DW0.MediaCommandOpcode = MEDIA_COMMAND_OPCODE_MEDIASTATEFLUSH;
                DW0.Pipeline = PIPELINE_MEDIA;
                DW0.CommandType = COMMAND_TYPE_GFXPIPE;

                DW1.Value = 0;
            }

            static const size_t dwSize = 2;
            static const size_t byteSize = 8;
        };

    //!
    //! \brief MI_USER_INTERRUPT
    //! \details
    //!     This command is used to communicate Force Wakeup request to PM unit. No
    //!     The MI_USER_INTERRUPT command is used to generate a User Interrupt
    //!     condition. The parser will continue parsing after processing this
    //!     command. See User Interrupt.
    //!
    struct MI_USER_INTERRUPT_CMD
    {
        union
        {
            struct
            {
                uint32_t                 Reserved0                                        : __CODEGEN_BITFIELD( 0, 22)    ; //!< Reserved
                uint32_t                 MiCommandOpcode                                  : __CODEGEN_BITFIELD(23, 28)    ; //!< MI_COMMAND_OPCODE
                uint32_t                 CommandType                                      : __CODEGEN_BITFIELD(29, 31)    ; //!< COMMAND_TYPE
            };
            uint32_t                     Value;
        } DW0;

        //! \name Local enumerations

        enum MI_COMMAND_OPCODE
        {
            MI_COMMAND_OPCODE_MIUSERINTERRUPT                                  = 2, //!< No additional details
        };

        enum COMMAND_TYPE
        {
            COMMAND_TYPE_MICOMMAND                                            = 0, //!< No additional details
        };

        //! \name Initializations

        //! \brief Explicit member initialization function
        MI_USER_INTERRUPT_CMD()
        {
            DW0.Value = 0x1000000;
            //DW0.MiCommandOpcode                              = MI_COMMAND_OPCODE_MIUSERINTERRUPT;
            //DW0.CommandType                                  = COMMAND_TYPE_MICOMMAND;
        }

        static const size_t dwSize = 1;
        static const size_t byteSize = 4;
    };

    };
}  // namesapce xe2_lpm_base_next
}  // namespace mi
}  // namespace mhw

#pragma pack()

#endif  // __MHW_MI_HWCMD_XE2_LPM_BASE_NEXT_H__