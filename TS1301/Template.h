#pragma once
#pragma once
#ifndef TEMALATE_H
#    define TEMPLATE_H

template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    while (first <= last) {
        int mid = first + (last - first) / 2;

        if (a[mid] == key) {
            found = true;
            location = mid;
            return;
        }

        if (a[mid] < key) {
            first = mid + 1;
        }

        else
        {
            last = mid - 1;
        }
    }
    found = false;
}

template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    if (first > last) {
        found = false;
        return;
    }

    int mid = first + (last - first) / 2;

    if (a[mid] == key) {
        found = true;
        location = mid;
        return;
    }

    if (a[mid] < key) {
        RecBinarySearch(a, mid + 1, last, key, found, location);
    } else {
        RecBinarySearch(a, first, mid - 1, key, found, location);
    }
}

#endif // !TEMALATE_H
