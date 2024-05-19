#ifndef MMBMPDATA_H
#define MMBMPDATA_H

#include <wx/bitmap.h>
#include <wx/listimpl.cpp>

WX_DECLARE_LIST(wxBitmap, BmpList);

class mmBmpData
{
    public:
        mmBmpData();
        virtual ~mmBmpData();

    protected:

    private:
};

#endif // MMBMPDATA_H
