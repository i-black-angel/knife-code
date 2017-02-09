/**
 * Copyright 2017 Shusheng Shao <iblackangel@163.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _MACROS_H_
#define _MACROS_H_

#include <stdlib.h>

#define SAFE_DELETE(x) do { if (NULL != x) { delete x; x = NULL; } } while(0)
#define ELEMENTS(x)  ( sizeof( (x) ) / sizeof( (x)[0] ) )

/* Singleton definition */
#define SINGLETON_DEFINE(ClassName)				\
public:											\
	static ClassName *instance();				\
	static void destroy();						\
private:										\
    static ClassName *_instance

/* Singleton Implement */
#define SINGLETON_IMPLEMNET(ClassName)			\
	ClassName *ClassName::_instance = NULL;		\
	ClassName *ClassName::instance()			\
	{											\
		if (NULL == _instance) {				\
			_instance = new ClassName();		\
		}										\
		return _instance;						\
	}											\
	void ClassName::destroy()					\
	{											\
		SAFE_DELETE(_instance);					\
	}

#endif /* _MACROS_H_ */
