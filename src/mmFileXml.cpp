/***************************************************************
 * Name:      mmodaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    AF (andrea202511@gmail.com)
 * Created:   2024-01-26
 * Copyright: AF ()
 * License:
 **************************************************************/


#include "mmodaMain.h"


#include <wx/intl.h>
#include <wx/string.h>
#include <wx/xml/xml.h>



void mmodaDialog::LoadFileXml(void)
{

    wxString str1;
    wxString str2;
    wxString log;

    wxXmlDocument docxml;
    wxXmlNode *child_liv1;
    wxXmlNode *child_liv2;
    wxXmlNode *child_liv3;

    int i_tmp;

    log="Opening file: "+XmlFileName+"\n";

    AddLog(log);

    if (!docxml.Load(XmlFileName))
    {
        AddLog("...Fail\n");
        return;
    }
    else
    {
        AddLog("...Done\n");
    }

    //Loop to find Frame/Items
    child_liv1 = docxml.GetRoot()->GetChildren();
    while (child_liv1)
    {
        str1=child_liv1->GetName();
        if (str1=="Frame")
        {
            Builder->InitFrame();
            child_liv2=child_liv1->GetChildren();
            while (child_liv2)
            {
                str1=child_liv2->GetName();
                str2=child_liv2->GetNodeContent();
                str2.ToInt(&i_tmp);

                if (str1=="Password")
                {
                }
                if (str1=="BkColor")
                {
                }
                if (str1=="DimHor")
                {
                    Builder->SetDimHor(i_tmp);
                }
                if (str1=="DimVer")
                {
                   Builder->SetDimVer(i_tmp);
                }
                child_liv2=child_liv2->GetNext();
            }
            Builder->SetFrame();
        }

        if (str1=="Items")
        {
            child_liv2=child_liv1->GetChildren();
            while (child_liv2)
            {
                str1=child_liv2->GetName();
                if (str1=="Button")
                {
                    Builder->InitButton();
                    child_liv3=child_liv2->GetChildren();
                    while (child_liv3)
                    {
                        str1=child_liv3->GetName();
                        str2=child_liv3->GetNodeContent();
                        str2.ToInt(&i_tmp);

                        if (str1=="PosHor")
                        {
                            Builder->SetPosHor(i_tmp);
                        }
                        if (str1=="PosVer")
                        {
                             Builder->SetPosVer(i_tmp);
                        }
                        if (str1=="DimHor")
                        {
                            Builder->SetDimHor(i_tmp);
                        }
                        if (str1=="DimVer")
                        {
                            Builder->SetDimVer(i_tmp);
                        }
                        if (str1=="Text")
                        {
                            Builder->SetText1(str2);
                        }
                        if (str1=="Mode")
                        {
                            Builder->SetFunc(i_tmp);
                        }
                        if (str1=="Coil")
                        {
                            Builder->SetRegc(i_tmp);
                        }
                       child_liv3=child_liv3->GetNext();
                    }
                    Builder->SetButton();
                }
                if (str1=="Statictext")
                {
                    Builder->InitStaticText();
                    child_liv3=child_liv2->GetChildren();
                    while (child_liv3)
                    {
                        str1=child_liv3->GetName();
                        str2=child_liv3->GetNodeContent();
                        str2.ToInt(&i_tmp);

                        if (str1=="PosHor")
                        {
                            Builder->SetPosHor(i_tmp);
                        }
                        if (str1=="PosVer")
                        {
                             Builder->SetPosVer(i_tmp);
                        }
                        if (str1=="Text")
                        {
                            Builder->SetText1(str2);
                        }
                        child_liv3=child_liv3->GetNext();
                    }
                    Builder->SetStaticText();
                }
                if (str1=="Staticbitmap")
                {
                    Builder->InitStaticIcon();
                    child_liv3=child_liv2->GetChildren();
                    while (child_liv3)
                    {
                        str1=child_liv3->GetName();
                        str2=child_liv3->GetNodeContent();
                        str2.ToInt(&i_tmp);

                        if (str1=="PosHor")
                        {
                            Builder->SetPosHor(i_tmp);
                        }
                        if (str1=="PosVer")
                        {
                             Builder->SetPosVer(i_tmp);
                        }
                        if (str1=="Text")
                        {
                            Builder->SetText1(str2);
                        }
                        child_liv3=child_liv3->GetNext();
                    }
                    Builder->SetStaticIcon();
                }
                if (str1=="Dinamicicon")
                {
                    Builder->InitDinamicIcon();
                    child_liv3=child_liv2->GetChildren();
                    while (child_liv3)
                    {
                        str1=child_liv3->GetName();
                        str2=child_liv3->GetNodeContent();
                        str2.ToInt(&i_tmp);

                        if (str1=="PosHor")
                        {
                            Builder->SetPosHor(i_tmp);
                        }
                        if (str1=="PosVer")
                        {
                             Builder->SetPosVer(i_tmp);
                        }
                        if (str1=="Icon0")
                        {
                            Builder->SetPar1(i_tmp);
                        }
                        if (str1=="Icon1")
                        {
                            Builder->SetPar2(i_tmp);
                        }
                        if (str1=="Coil")
                        {
                            Builder->SetRegc(i_tmp);
                        }
                        child_liv3=child_liv3->GetNext();
                    }
                    Builder->SetDinamicIcon();
                }
                if (str1=="Numericfield")
                {
                    Builder->InitTextCtrl();
                    child_liv3=child_liv2->GetChildren();
                    while (child_liv3)
                    {
                        str1=child_liv3->GetName();
                        str2=child_liv3->GetNodeContent();
                        str2.ToInt(&i_tmp);

                        if (str1=="PosHor")
                        {
                            Builder->SetPosHor(i_tmp);
                        }
                        if (str1=="PosVer")
                        {
                             Builder->SetPosVer(i_tmp);
                        }
                        if (str1=="Mode")
                        {
                            Builder->SetFunc(i_tmp);
                        }
                        if (str1=="Decimal")
                        {
                            Builder->SetPar1(i_tmp);
                        }
                        if (str1=="Lenght")
                        {
                            Builder->SetPar2(i_tmp);
                        }
                        if (str1=="ReadOnly")
                        {
                            Builder->SetPar3(i_tmp);
                        }
                        if (str1=="Register")
                        {
                            Builder->SetRegc(i_tmp);
                        }
                        child_liv3=child_liv3->GetNext();
                    }
                    Builder->SetTextCtrl();
                }
                child_liv2=child_liv2->GetNext();
            }
        }
        if (str1=="Resources")
        {
            child_liv2=child_liv1->GetChildren();
            while (child_liv2)
            {
                str1=child_liv2->GetName();
                str2=child_liv2->GetNodeContent();
                if (str1=="Bitmap")
                {
                    Builder->AddBitmap(str2);
                }
                child_liv2=child_liv2->GetNext();
            }
        }
        child_liv1=child_liv1->GetNext();
    }
    Builder->ShowFrame();
    docxml.DetachDocumentNode();
}
