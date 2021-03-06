// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#pragma once
#include "MedusaPreDeclares.h"
#include "IPredicate.h"

MEDUSA_BEGIN;

struct TruePredicate :public IPredicate
{
	MEDUSA_DECLARE_PREDICATE(TruePredicate,IPredicate);
public:
	virtual int Evaluate(void*)const override { return 1; }
};
MEDUSA_ENABLE_STATIC_CONSTRUCTOR(TruePredicate);


MEDUSA_END;
