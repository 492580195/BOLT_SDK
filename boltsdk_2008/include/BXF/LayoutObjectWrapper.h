/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   LayoutObjectWrapper
*   Author      :   ������
*   Create      :   2013-5-19 0:05
*   LastChange  :   2013-5-19 0:05
*   History     :	
*
*   Description :   BOLT��Ԫ����C++������
*
********************************************************************/ 
#ifndef __LAYOUTOBJECTWRAPPER_H__
#define __LAYOUTOBJECTWRAPPER_H__

#include <XLUE.h>
#include <BXF/ObjectTreeWrapper.h>

namespace Xunlei
{
namespace Bolt
{

class LayoutObjectWrapper
{
public:

	XLUE_LAYOUTOBJ_HANDLE m_hObj;

public:

	LayoutObjectWrapper(XLUE_LAYOUTOBJ_HANDLE hObj = NULL):
	  m_hObj(hObj)
	{
	}

	LayoutObjectWrapper& operator=(XLUE_LAYOUTOBJ_HANDLE hObj)
	{
		m_hObj = hObj;

		return *this;
	}

	void Attach(XLUE_LAYOUTOBJ_HANDLE hNewObj)
	{
		assert(m_hObj == NULL);
		assert((hNewObj == NULL) || XLUE_IsObjValid(hNewObj));

		m_hObj = hNewObj;
	}

	XLUE_LAYOUTOBJ_HANDLE Detach()
	{
		XLUE_LAYOUTOBJ_HANDLE hObj = m_hObj;
		m_hObj = NULL;

		return hObj;
	}

	operator XLUE_LAYOUTOBJ_HANDLE() const
	{ 
		return m_hObj; 
	}

public:

	bool IsValid() const
	{
		return ((m_hObj !=NULL) && (!!XLUE_IsObjValid(m_hObj)));
	}

	const char* GetClass() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjClassName(m_hObj);
	}

	const char* GetID() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjID(m_hObj);
	}
	
	ObjectTreeWrapper GetOwner() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return ObjectTreeWrapper(XLUE_GetObjOwner(m_hObj));
	}

	LayoutObjectWrapper GetFather() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetObjFather(m_hObj));
	}

	bool IsChild(XLUE_LAYOUTOBJ_HANDLE hObj) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_IsChild(m_hObj, hObj);
	}

	long AddChild(XLUE_LAYOUTOBJ_HANDLE hObj) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_AddObjChild(m_hObj, hObj);
	}

	long RemoveChild(XLUE_LAYOUTOBJ_HANDLE hObj) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_RemoveObjChild(m_hObj, hObj);
	}

	long RemoveAllChild() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_RemoveObjAllChildren(m_hObj);
	}

	size_t GetChildCount() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjChildCount(m_hObj);
	}

	LayoutObjectWrapper GetChild(size_t index) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetObjChild(m_hObj, index));
	}

	LayoutObjectWrapper GetChildByID(const char* id) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetObjChildByID(m_hObj, id));
	}

	//ͨ����λָ������ȡָ����object
	LayoutObjectWrapper GetObject(const char* cmd) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetObjChildByCmd(m_hObj, cmd));
	}

	LayoutObjectWrapper GetControlObject(const char* id) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetControlObject(m_hObj, id));
	}

	LayoutObjectWrapper GetControlObjectEx(const char* id) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetControlObjectEx(m_hObj, id));
	}

	LayoutObjectWrapper GetOwnerControl() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return LayoutObjectWrapper(XLUE_GetOwnerControl(m_hObj));
	}

	bool IsControl() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_IsControl(m_hObj);
	}

	// λ����غ���
	const RECT* GetObjPos() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjPos(m_hObj);
	}

	const RECT* GetAbsPos() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjAbsPos(m_hObj);
	}

	long SetObjPos(const RECT* lpNewPos) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjPos(m_hObj, lpNewPos);
	}

	long SetObjPos(const char* lpLeft, const char* lpTop, const char* lpWidth, const char* lpHeight) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjPosExp(m_hObj, lpLeft, lpTop, lpWidth, lpHeight);
	}

	long SetObjPosExp2(XLUE_LAYOUTOBJ_HANDLE hObj, const char* lpLeft, const char* lpTop, const char* lpRight, const char* lpBottom) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjPosExp2(m_hObj, lpLeft, lpTop, lpRight, lpBottom);
	}

	const RECT* GetObjAbsPos(XLUE_LAYOUTOBJ_HANDLE hObj) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjAbsPos(m_hObj);
	}


	// �����غ���
	const char* GetCursorID(long x, long y) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjCursorID(m_hObj, x, y);
	}

	void SetCursorID(const char* id)
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjCursorID(m_hObj, id);
	}

	// �����limit������غ���
	bool IsLimitChild() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_IsObjLimitChild(m_hObj);
	}

	void SetLimitChild(bool limit)
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjLimitChild(m_hObj, limit? TRUE : FALSE);
	}

	// �����Ƿ�parent��limitchild��������
	bool IsLimit() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_IsObjLimit(m_hObj);
	}

	void SetLimit(bool limit) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjLimit(m_hObj, limit? TRUE : FALSE);
	}

	//�õ������Ƶľ���,���û������,�򷵻�false
	bool GetLimitRect(RECT* lpLimitRect) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjLimitRect(m_hObj, lpLimitRect);
	}

	//�õ�������Ƶ�����
	bool GetCaretLimitRect(RECT* lpLimitRect) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjCaretLimitRect(m_hObj, lpLimitRect);
	}

	// ���pRect = NULL���ʾ��������������Ϊ��Ч
	// pDirty��Ԫ��������ϵ�������Ԫ��������Ͻ�
	void PushDirtyRect(const RECT* lpRect) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_ObjPushDirtyRect(m_hObj, lpRect);
	}

	// �����visible�������
	bool GetVisible() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjVisible(m_hObj);
	}

	void SetVisible(bool visible, bool isRecursive = false) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjVisible(m_hObj, visible? TRUE : FALSE, isRecursive? TRUE : FALSE);
	}

	bool GetChildrenVisible() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjChildrenVisible(m_hObj);
	}

	void SetChildrenVisible(bool visible)
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjChildrenVisible(m_hObj, visible? TRUE : FALSE);
	}

	bool GetFatherVisible() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjFatherVisible(m_hObj);
	}

	bool GetPrivateVisible() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjPrivateVisible(m_hObj);
	}

	// Ԫ�����enable������ط���
	bool GetEnable() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjEnable(m_hObj);
	}

	void SetEnable(bool enable, bool isRecursive = false) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjEnableEx(m_hObj, enable? TRUE : FALSE, isRecursive? TRUE : FALSE);
	}

	bool GetChildrenEnable() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjChildrenEnable(m_hObj);
	}

	void SetChildrenEnable(bool bEnable) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjChildrenEnable(m_hObj, bEnable? TRUE : FALSE);
	}

	bool GetFatherEnable() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjFatherEnable(m_hObj);
	}

	bool GetPrivateEnable() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjPrivateEnable(m_hObj);
	}

	// Ԫ�����zorder������ط���
	long GetZorder() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjZorder(m_hObj);
	}

	void SetZorder(long zorder) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjZorder(m_hObj, zorder);
	}

	long GetAbsZorder() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjAbsZorder(m_hObj);
	}

	
	// ���ͼ��������¼���غ���
	void EnableInputTarget(bool enable) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_EnableObjInputTarget(m_hObj, enable? TRUE : FALSE);
	}

	bool CanHandleInput() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_CanObjHandleInput(m_hObj);
	}

	// ������غ���
	void SetFocus(bool focus) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjFocus(m_hObj, focus? TRUE : FALSE);
	}

	void SetFocusEx(bool isFocus, FocusReason reason) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjFocusEx(m_hObj, isFocus? TRUE : FALSE, reason);
	}

	bool GetFocus() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjFocus(m_hObj);
	}

	// �������
	void SetFocusStrategy(FocusStrategy strategy) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjFocusStrategy(m_hObj, strategy);
	}

	FocusStrategy GetFocusStrategy() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjFocusStrategy(m_hObj);
	}

	// Ԫ�������겶��״̬��غ���
	void SetCaptureMouse(bool isCapture) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjCaptureMouse(m_hObj, isCapture? TRUE : FALSE);
	}

	bool GetCaptureMouse() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjCaptureMouse(m_hObj);
	}

	// Ԫ�����taborder������غ���
	void SetTabOrder(long newOrder) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjTabOrder(m_hObj, newOrder);
	}

	long GetTabOrder() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjTabOrder(m_hObj);
	}

	void SetTabGroup(long newTabGroup) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjTabGroup(m_hObj, newTabGroup);
	}

	long GetTabGroup() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjTabGroup(m_hObj);
	}

	void SetTabStop(bool tabStop) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjTabStop(m_hObj, tabStop);
	}

	bool GetTabStop() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjTabStop(m_hObj);
	}

	unsigned char GetAlpha() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetRenderObjAlpha(m_hObj);
	}

	void SetAlpha(unsigned char alpha, bool isRecursive = false) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetRenderObjAlphaEx(m_hObj, alpha, isRecursive? TRUE : FALSE);
	}

	// Ԫ�����mask��غ���
	void SetInheritMask(bool isInherit, bool isRecursive = false) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjInheritMask(m_hObj, isInherit? TRUE : FALSE, isRecursive? TRUE : FALSE);
	}

	bool IsInheritMask() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjInheritMask(m_hObj);
	}

	const RECT* GetMaskPos() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjMaskPos(m_hObj);
	}

	void SetMaskBlendType(unsigned long blendtype) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjMaskBlendType(m_hObj, blendtype);
	}

	unsigned long GetMaskBlendType() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_GetObjMaskBlendType(m_hObj);
	}

	// Ԫ������ק��غ���
	void SetDropEnable(bool bEnableDrop) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_SetObjMaskBlendType(m_hObj, bEnableDrop? TRUE : FALSE);
	}

	bool GetDropEnable() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_GetObjDropEnable(m_hObj);
	}

	// ����Ⱦ��غ���
	bool BindLayer(XLUE_LAYOUTOBJ_HANDLE hLayerObj, bool isRecursive = false) const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return !!XLUE_ObjBindLayer(m_hObj, hLayerObj, isRecursive? TRUE : FALSE);
	}

	XLUE_LAYOUTOBJ_HANDLE GetLayer() const
	{
		assert(m_hObj);
		assert(XLUE_IsObjValid(m_hObj));

		return XLUE_ObjGetLayer(m_hObj);
	}

	//bool SetResProvider(IResProvider *pResProvider);
	//IResProvider* GetResProvider() const;
};

} // Bolt
} // Xunlei

#endif // __LAYOUTOBJECTWRAPPER_H__