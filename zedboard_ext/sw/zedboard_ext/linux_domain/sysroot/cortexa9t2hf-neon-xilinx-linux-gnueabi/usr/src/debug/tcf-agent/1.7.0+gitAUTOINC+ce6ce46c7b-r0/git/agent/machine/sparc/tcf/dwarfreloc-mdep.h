/*******************************************************************************
 * Copyright (c) 2018-2021 Cobham Gaisler and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 * The Eclipse Public License is available at
 * http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 * You may elect to redistribute this code under either of these licenses.
 *
 * Contributors:
 *     Cobham Gaisler - initial API and implementation
 *******************************************************************************/

/*
 * This module provides CPU specific ELF definitions for SPARC.
 */

#define R_SPARC_NONE      0
#define R_SPARC_32        3
#define R_SPARC_UA32     23

static void elf_relocate(void) {
    if (relocs->type == SHT_REL && reloc_type != R_SPARC_NONE) {
        U4_T x = *(U4_T *)((char *)section->data + reloc_offset);
        if (section->file->type != ET_REL)
            str_exception(ERR_INV_FORMAT, "Invalid relocation record");
        if (section->file->byte_swap) SWAP(x);
        assert(reloc_addend == 0);
        reloc_addend = x;
    }
    switch (reloc_type) {
    case R_SPARC_NONE:
        *destination_section = NULL;
        break;
    case R_SPARC_32:
    case R_SPARC_UA32:
        if (data_size < 4)
            str_exception(ERR_INV_FORMAT, "Invalid relocation record");
        *(U4_T *)data_buf = (U4_T)(sym_value + reloc_addend);
        break;
    default:
        str_fmt_exception(ERR_INV_FORMAT, "Unsupported relocation type %u", (unsigned)reloc_type);
    }
}
