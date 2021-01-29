Test001()
{
     if (TRUE)
     {
          while (*p == ' ') p++;
          if (I>0) I--;
     }     
     else
          for (I=0;I<10;I++)
     	       CReObject;
     TestElse;
     switch (ch) {
         case 'a' :
            printf("\nOption a was selected.\n");
            break;
         case 'b' :
         default :
            printf("\nNOT A VALID CHOICE!  Bye ...");
            return(-1);
         case 'c' :
            printf("\nOption b or c was selected.\n");
            break;
         }
     do {
          printf ("Enter password: ");
          scanf("%s", password);
     } while (strcmp(password, checkword));
}


STDMETHODIMP CRichEditView::XRichEditOleCallback::GetDragDropEffect(
	BOOL fDrag, DWORD grfKeyState, LPDWORD pdwEffect)
{
	if (!fDrag) // allowable dest effects
	{
		DWORD dwEffect;
		// check for force link
		if ((grfKeyState & (MK_CONTROL|MK_SHIFT)) == (MK_CONTROL|MK_SHIFT))
			dwEffect = DROPEFFECT_LINK;
		// check for force copy
		else if ((grfKeyState & MK_CONTROL) == MK_CONTROL)
			dwEffect = DROPEFFECT_COPY;
		// check for force move
		else if ((grfKeyState & MK_ALT) == MK_ALT)
			dwEffect = DROPEFFECT_MOVE;
		// default -- recommended action is move
		else
			dwEffect = DROPEFFECT_MOVE;
		if (dwEffect & *pdwEffect) // make sure allowed type
			*pdwEffect = dwEffect;
	}
	return S_OK;
}


void CRichEditView::DoPaste(COleDataObject& dataobj, CLIPFORMAT cf, HMETAFILEPICT hMetaPict)
{
	CWaitCursor wait;

	CRichEditCntrItem* pItem = NULL;
	TRY
	{
		// create item from dialog results
		pItem = GetDocument()->CreateClientItem();
		pItem->m_bLock = TRUE;

		if (m_nPasteType == COlePasteSpecialDialog::pasteLink)      // paste link
		{
			if (!pItem->CreateLinkFromData(&dataobj))
				AfxThrowMemoryException();  // any exception will do
		}
		else if (m_nPasteType == COlePasteSpecialDialog::pasteNormal)
		{
			if (!pItem->CreateFromData(&dataobj))
				AfxThrowMemoryException();      // any exception will do
		}
		else if (m_nPasteType == COlePasteSpecialDialog::pasteStatic)
		{
			if (!pItem->CreateStaticFromData(&dataobj))
				AfxThrowMemoryException();      // any exception will do
		}
		else
		{
			// paste embedded
			if (!pItem->CreateFromData(&dataobj) &&
				!pItem->CreateStaticFromData(&dataobj))
			{
				AfxThrowMemoryException();      // any exception will do
			}
		}

		if (cf == 0)
		{
			// copy the current iconic representation
			FORMATETC fmtetc;
			fmtetc.cfFormat = CF_METAFILEPICT;
			fmtetc.dwAspect = DVASPECT_ICON;
			fmtetc.ptd = NULL;
			fmtetc.tymed = TYMED_MFPICT;
			fmtetc.lindex = 1;
			HGLOBAL hObj = dataobj.GetGlobalData(CF_METAFILEPICT, &fmtetc);
			if (hObj != NULL)
			{
				pItem->SetIconicMetafile(hObj);
				// the following code is an easy way to free a metafile pict
				STGMEDIUM stgMed;
				memset(&stgMed, 0, sizeof(stgMed));
				stgMed.tymed = TYMED_MFPICT;
				stgMed.hGlobal = hObj;
				ReleaseStgMedium(&stgMed);
			}

			// set the current drawing aspect
			hObj = dataobj.GetGlobalData((CLIPFORMAT)_oleData.cfObjectDescriptor);
			if (hObj != NULL)
			{
				ASSERT(hObj != NULL);
				// got CF_OBJECTDESCRIPTOR ok.  Lock it down and extract size.
				LPOBJECTDESCRIPTOR pObjDesc = (LPOBJECTDESCRIPTOR)GlobalLock(hObj);
				ASSERT(pObjDesc != NULL);
				((COleClientItem*)pItem)->SetDrawAspect((DVASPECT)pObjDesc->dwDrawAspect);
				GlobalUnlock(hObj);
				GlobalFree(hObj);
			}
		}
		else
		{
			if (hMetaPict != NULL)
			{
				pItem->SetIconicMetafile(hMetaPict);
				((COleClientItem*)pItem)->SetDrawAspect(DVASPECT_ICON);
			}
			else
				((COleClientItem*)pItem)->SetDrawAspect(DVASPECT_CONTENT);
		}


		HRESULT hr = InsertItem(pItem);
		pItem->UpdateItemType();

		pItem->m_bLock = FALSE;

		if (hr != NOERROR)
			AfxThrowOleException(hr);

	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			pItem->m_bLock = FALSE;
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
	}
	END_CATCH
}


