/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 *
 * Copyright (C) 2017 Jorgen Lundman <lundman@lundman.net>
 *
 */

#include <sys/processor.h>

uint32_t
cpu_number(void)
{
	uint32_t cpuid;
	cpuid = (uint32_t)KeGetCurrentProcessorIndex();
	return cpuid % max_ncpus;
	return 0;
	return cpuid >= max_ncpus ? 0 : cpuid;
}

uint32_t
getcpuid()
{
	uint32_t cpuid;
	cpuid = (uint32_t)KeGetCurrentProcessorIndex();
	return cpuid % max_ncpus;
	return 0;
	return cpuid >= max_ncpus ? 0 : cpuid;
}

extern void __cpuid(int* CPUInfo, int InfoType);
uint64_t spl_cpuid_features(void)
{
	int CPUInfo[4] = { -1 };
	__cpuid(CPUInfo, 0);
	return 0;
}

uint64_t spl_cpuid_leaf7_features(void)
{
	int registers[4];
	__cpuidex(registers, 0x7, 0);
	return 0;
}
