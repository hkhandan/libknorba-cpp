/*---[Message.cpp]---------------------------------------------m(._.)m--------*\
 |
 |  Project   : KnoRBA C++ Library
 |  Declares  : -
 |  Implements: knorba::MessageSet::*
 |
 |  Copyright (c) 2013, 2014, 2015, RIKEN (The Institute of Physical and
 |  Chemial Research) All rights reserved.
 |
 |  Author: Hamed KHANDAN (hamed.khandan@port.kobe-u.ac.jp)
 |
 |  This file is distributed under the KnoRBA Free Public License. See
 |  LICENSE.TXT for details.
 |
 *//////////////////////////////////////////////////////////////////////////////

// KFoundation
#include <kfoundation/Ref.h>
#include <kfoundation/RefArray.h>

#include "Message.h"
#include "Group.h"

#include "MessageSet.h"

namespace knorba {

  using namespace kfoundation;
  
// --- (DE)CONSTRUCTORS --- //

  /** Sole constructor. */

  MessageSet::MessageSet() {
    _items = new RefArray<Message>();
    _senders = new Group();
  }

  
// --- METHODS --- //

  /** Adds a message to this set. */

  void MessageSet::add(Ref<Message> msg) {
    _items->push(msg);
    _senders->add(msg->getSender());
  }


  /** Returns the number of message in this set. */
  
  k_integer_t MessageSet::getSize() const {
    return _items->getSize();
  }


  /** Returns the message at the given index. */
  
  Ref<Message> MessageSet::get(int index) const {
    return _items->at(index);
  }
  

  /**
   * Returns the GUIDs of all senders of messages in this set.
   */

  Ref<Group> MessageSet::getSenders() const {
    return _senders;
  }


  /**
   * Checks if this set is empty.
   */
  
  bool MessageSet::isEmpty() const {
    return _items->isEmpty();
  }


  /**
   * Removes all messages in this set.
   */

  void MessageSet::clear() {
    _items->clear();
  }
  
} // namespace knorba