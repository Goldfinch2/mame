// license:BSD-3-Clause
// copyright-holders:Sergey Svishchev
/*********************************************************************

    formats/ds9_dsk.h

*********************************************************************/
#ifndef MAME_FORMATS_DS9_DSK_H
#define MAME_FORMATS_DS9_DSK_H

#pragma once

#include "flopimg.h"
#include "formats/basicdsk.h"

LEGACY_FLOPPY_OPTIONS_EXTERN(ds9);

class ds9_format : public floppy_image_format_t
{
public:
	ds9_format();

	virtual int identify(util::random_read &io, uint32_t form_factor, const std::vector<uint32_t> &variants) override;
	virtual bool load(util::random_read &io, uint32_t form_factor, const std::vector<uint32_t> &variants, floppy_image *image) override;

	virtual const char *name() const override;
	virtual const char *description() const override;
	virtual const char *extensions() const override;
	virtual bool supports_save() const override { return false; }

	static const desc_e ds9_desc[];

private:
	void find_size(util::random_read &io, uint8_t &track_count, uint8_t &head_count, uint8_t &sector_count);
};

extern const floppy_format_type FLOPPY_DS9_FORMAT;

#endif // MAME_FORMATS_DS9_DSK_H
