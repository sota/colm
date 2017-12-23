/*
 * Copyright 2002 Adrian Thurston <thurston@colm.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifndef _AAPL_SBSTTABLE_H
#define _AAPL_SBSTTABLE_H

#include "compare.h"
#include "svector.h"

/**
 * \addtogroup bst 
 * @{
 */

/** 
 * \class SBstTable
 * \brief Copy-on-write binary search table for structures that contain a key.
 *
 * This is a basic binary search table that employs a copy-on-write data
 * storage mechanism. It can be used to contain a structure that has a key and
 * possibly some data. The key should be a member of the element class and
 * accessible with getKey(). A class containing the compare routine must be
 * supplied.
 */

/*@}*/

#define BST_TEMPL_DECLARE class Element, class Key, \
		class Compare = CmpOrd<Key>, class Resize = ResizeExpn
#define BST_TEMPL_DEF class Element, class Key, class Compare, class Resize
#define BST_TEMPL_USE Element, Key, Compare, Resize
#define GET_KEY(el) ((el).getKey())
#define BstTable SBstTable
#define Vector SVector
#define Table STable
#define BSTTABLE
#define SHARED_BST

#include "bstcommon.h"

#undef BST_TEMPL_DECLARE
#undef BST_TEMPL_DEF
#undef BST_TEMPL_USE
#undef GET_KEY
#undef BstTable
#undef Vector
#undef Table
#undef BSTTABLE
#undef SHARED_BST

/**
 * \fn SBstTable::insert(const Key &key, Element **lastFound)
 * \brief Insert a new element with the given key.
 *
 * If the given key does not already exist in the table a new element is
 * inserted with the given key. A constructor taking only const Key& is used
 * to initialize the new element. If lastFound is given, it is set to the new
 * element created. If the insert fails then lastFound is set to the existing
 * element with the same key. 
 *
 * \returns The new element created upon success, null upon failure.
 */

/**
 * \fn SBstTable::insertMulti(const Key &key)
 * \brief Insert a new element even if the key exists already.
 *
 * If the key exists already then the new element is placed next to some
 * element with the same key. InsertMulti cannot fail. A constructor taking
 * only const Key& is used to initialize the new element.
 *
 * \returns The new element created.
 */

#endif /* _AAPL_SBSTTABLE_H */
