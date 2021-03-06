// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#include "MedusaPreCompiled.h"
#include "Node/Input/EventArg/KeyDownEventArg.h"
MEDUSA_BEGIN;

KeyDownEventArg::KeyDownEventArg(uint keyData,uint status):BaseKeyEventArg(keyData,status)
{
	/*
	lParam 
		The repeat count, scan code, extended-key flag, context code, previous key-state flag, and transition-state flag, as shown following.

		0-15 The repeat count for the current message. The value is the number of times the keystroke is autorepeated as a result of the user holding down the key. If the keystroke is held long enough, multiple messages are sent. However, the repeat count is not cumulative. 
		16-23 The scan code. The value depends on the OEM. 
		24 Indicates whether the key is an extended key, such as the right-hand ALT and CTRL keys that appear on an enhanced 101- or 102-key keyboard. The value is 1 if it is an extended key; otherwise, it is 0. 
		25-28 Reserved; do not use. 
		29 The context code. The value is always 0 for a WM_KEYDOWN message. 
		30 The previous key state. The value is 1 if the key is down before the message is sent, or it is zero if the key is up. 
		31 The transition state. The value is always 0 for a WM_KEYDOWN message. 

		*/


}


MEDUSA_END;