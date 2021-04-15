#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> p_rev = nullptr;
  ElementPtr<T> p_help = q.head;
  ElementPtr<T> new_element = new Element<T>;
  new_element->data = value;
  new_element->priority = priority;
  new_element->next = nullptr;
  if (q.head == nullptr && q.tail == nullptr) 
  {
    q.head = new_element;
    q.tail = new_element;
  } 
  else 
  {
    while (new_element->priority <= p_help->priority) 
    {
      if (p_help->next == nullptr) 
      break;
      p_rev = p_help;
      p_help = p_help->next;
    }
    if (p_help == q.head && new_element->priority > p_help->priority)
    {
      new_element->next = p_help;
      q.head = new_element;
    }
    else if (p_help == q.tail && new_element->priority < p_help->priority)
    {
      p_help->next = new_element;
      q.tail = new_element;
    }
    else
    {
      p_rev->next = new_element;
      new_element->next = p_help;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> del_element;
  if (q.head == nullptr and q.tail == nullptr)
  {
    del_element = nullptr;
  }
  else if (q.head->next == nullptr)
  {
    del_element = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }
  else
  {
    del_element = q.head;
    q.head = q.head->next;
    del_element->next = nullptr;
  }
  delete del_element;
  
}

}  // namespace priority_queue

}  // namespace strukdat
