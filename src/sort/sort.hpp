#include <cstddef>
#include <algorithm>
#include <functional>

enum class Ordering {
  LT,
  EQ,
  GT
};

template <typename T>
using Comparator = std::function<Ordering(const T&, const T&)>;

template <typename T>
Comparator<T> standardComparator = [](const T& a, const T& b) -> Ordering {
  if (a == b) return Ordering::EQ;
  if (a < b) return Ordering::LT;
  return Ordering::GT;
};

// Hoare partition scheme
template <typename T>
size_t partition(
    T *array, size_t first, size_t last,
    Comparator<T> cmp = standardComparator<T>
) {
  T pivot = array[first];

  int i = first - 1;
  int j = last + 1;

  while (true) {
    do {
      i++;
    } while (cmp(array[i], pivot) == Ordering::LT);

    do {
      j--;
    } while (cmp(array[j], pivot) == Ordering::GT);

    if (i >= j) {
      return j;
    }

    std::swap(array[i], array[j]);
  }
}

template <typename T>
void quicksort(
    T *array, size_t first, size_t last,
    Comparator<T> cmp = standardComparator<T>
) {
  if (first >= last) {
    return;
  }

  size_t split = partition(array, first, last, cmp);
  quicksort(array, first, split, cmp);
  quicksort(array, split + 1, last, cmp);
}

template <typename T>
void quicksort(
    T *array, size_t size,
    Comparator<T> cmp = standardComparator<T>
) {
  if (size <= 1) {
    return;
  }
  quicksort(array, 0, size - 1, cmp);
}

template <typename T>
void insertsort(
    T *array, size_t size,
    Comparator<T> cmp = standardComparator<T>
) {
  if (size <= 1) {
    return;
  }

  /*
   * Simpler but less performant
   *
   * for (size_t i = 0; i < size; i++) {
   *   for (size_t j = i; j > 0 && array[j] < array[j-1]; j--) {
   *     std::swap(array[j], array[j-1]);
   *   }
   * }
   */

  for (size_t i = 1; i < size; i++) {
    if (cmp(array[i], array[i-1]) == Ordering::LT) {
      T x = std::move(array[i]);
      int j;
      for (j = i - 1; j >= 0 && cmp(array[j], x) == Ordering::GT; j--) {
        array[j+1] = array[j];
      }
      array[j+1] = std::move(x);
    }
  }
}

template <typename T>
void selectsort(
    T *array, size_t size,
    Comparator<T> cmp = standardComparator<T>
) {
  for (size_t i = 0; i < size; i++) {
    T *min = std::min_element(array + i, array + size, [&cmp](const T& a, const T& b){
      return cmp(a, b) == Ordering::LT;
    });
    if (array + i != min) {
      std::swap(*(array + i), *min);
    }
  }
}

template <typename T>
void mergesort(
    T* array, size_t size,
    Comparator<T> cmp = standardComparator<T>
) {
  T *copy = new T[size];
  std::copy(array, array + size, copy);
  splitMerge(copy, 0, size - 1, array, cmp);
  delete copy;
}

template <typename T>
void splitMerge(
    T* source, size_t begin, size_t end, T* target,
    Comparator<T> cmp = standardComparator<T>
) {
  if (end - begin < 2) {
    return;
  }

  size_t middle = (begin + end) / 2;

  splitMerge(target, begin, middle, source, cmp);
  splitMerge(target, middle + 1, end, source, cmp);

  merge(source, begin, middle, end, target, cmp);
}

template <typename T>
void merge(
    T* source, size_t begin, size_t middle, size_t end, T* target,
    Comparator<T> cmp = standardComparator<T>
) {
  size_t i = begin;
  size_t j = end;

  for (size_t k = begin; k < end; k++) {
    if (i < middle && (j >= end || cmp(source[i], source[j]) != Ordering::GT)) {
      target[k] = source[i];
      i++;
    } else {
      target[k] = source[j];
      j++;
    }
  }
}
