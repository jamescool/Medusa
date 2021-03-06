// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#pragma once

#include "Node/Panel/ScrollPanel.h"
#include "ListBoxItem.h"
#include "Core/Collection/Queue.h"
#include "Core/Collection/Dictionary.h"
#include "Core/Pattern/Event.h"
#include "Node/Binding/TListDataBinding.h"

MEDUSA_BEGIN;

/*
Pull to refresh
auto load on bottom
cache
vary type child
vary size child
*/
class ListBox :public ScrollPanel
{
	MEDUSA_NODE(ListBox, ScrollPanel);
public:
	typedef Delegate<void(ListBox& sender, const ListBoxItem& item)> ItemSelectedDelegate;
	typedef Delegate<void(ListBox& sender, const ListBoxItem& item)> ItemUnselectedDelegate;
	typedef Delegate<void(ListBox& sender, const ListBoxItem& item)> ItemClickedDelegate;

	typedef Event<void(ListBox& sender, const ListBoxItem& item)> ItemSelectedEvent;
	typedef Event<void(ListBox& sender, const ListBoxItem& item)> ItemUnselectedEvent;
	typedef Event<void(ListBox& sender, const ListBoxItem& item)> ItemClickedEvent;

	ItemUnselectedEvent OnItemUnselected;
	ItemSelectedEvent OnItemSelected;
	ItemClickedEvent OnItemClicked;
public:
	ListBox(StringRef name = StringRef::Empty, const IEventArg& e = IEventArg::Empty);
	ListBox(StringRef name, ScrollDirection direction);
	virtual ~ListBox(void);
	virtual bool Initialize() override;
	float ItemFixedSize() const { return mItemFixedSize; }
	void SetItemFixedSize(float val) { mItemFixedSize = val; }
public:
	virtual void SetScrollDirection(ScrollDirection direction)override;
	virtual bool SetBinding(IDataBinding* val)override;
	
	virtual void ScrollToIndex(uint index);
	virtual void ScrollByIndex(int index);

	virtual uint CurrentIndex()const;
	INode* GetNodeByIndex(uint index)const;
protected:
	virtual void OnMoveChildren()override;

	virtual bool ArrangeChildren(const Rect2F& limitRect = Rect2F::Zero, NodeLayoutArrangeFlags arrangeFlags = NodeLayoutArrangeFlags::None)override;
	virtual bool IsSensitiveToChildLayoutChanged(const ILayoutable& sender, NodeLayoutChangedFlags changedFlag)override;

	void OnItemAdded(size_t index);
	void OnItemRemoved(size_t index);
	void OnItemUpdated(size_t index);
	void OnTotalChanged();

	virtual void OnSwipeBegin(INode* sender, SwipeBeginGestureEventArg& e)override;
	virtual void OnSwipeMoved(INode* sender, SwipeMovedGestureEventArg& e)override;
	virtual void OnSwipeFailed(INode* sender, SwipeFailedGestureEventArg& e)override;
	virtual void OnSwipeSuccess(INode* sender, SwipeSuccessGestureEventArg& e)override;

protected:
	void LoadItemNode(ListBoxItem& item,bool forceReload=false, bool forceApplyMovement = false);
	void RecycleItemNode(ListBoxItem& item);
	bool TryLoadOrRecycleItem(ListBoxItem& item, bool forceReload = false,bool forceApplyMovement=false);
protected:
	virtual void OnBeforeMeasure(const Size2F& availableSize)override;

	void ClearCache();
	Size2F GetItemLimitSize()const;

	bool AssertValid()const;
	Size2F CalculateBoundingBoxSize(size_t index)const;
	const ListBoxItem* GetSelectedItem(Point2F pos)const;
	void SetupItems();
protected:
	List<ListBoxItem> mItems;
	const ListBoxItem* mSelectedItem = nullptr;
	RangeI mValidRange;
	float mItemFixedSize=0.f;
	float mResultItemFixedSize = 0.f;

	Queue<INode*> mSingleTypeItemCache;	//node cache for single type
	Dictionary<uint, Queue<INode*>* > mMultipleTypeItemCache;	//node cache for multiple type
	bool mCacheEnabed = false;
};

MEDUSA_ENABLE_STATIC_CONSTRUCTOR(ListBox);

MEDUSA_END;
