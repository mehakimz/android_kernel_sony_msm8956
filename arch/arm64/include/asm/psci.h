/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Copyright (C) 2013 ARM Limited
 */

#ifndef __ASM_PSCI_H
#define __ASM_PSCI_H

int psci_init(void);

struct psci_power_state {
	u16	id;
	u8	type;
	u8	affinity_level;
};

struct psci_operations {
	int (*get_version)(void);
	int (*cpu_suspend)(unsigned long state_id,
			   unsigned long entry_point);
	int (*cpu_off)(struct psci_power_state state);
	int (*cpu_on)(unsigned long cpuid, unsigned long entry_point);
	int (*migrate)(unsigned long cpuid);
	int (*affinity_info)(unsigned long target_affinity,
			unsigned long lowest_affinity_level);
	int (*migrate_info_type)(void);
};

extern struct psci_operations psci_ops;
#ifdef CONFIG_HARDEN_BRANCH_PREDICTOR
int psci_apply_bp_hardening(void);
#endif /* CONFIG_HARDEN_BRANCH_PREDICTOR */

#endif /* __ASM_PSCI_H */
