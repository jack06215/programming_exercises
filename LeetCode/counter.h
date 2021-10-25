#pragma once

#include <initializer_list>
#include <unordered_map>
#include <vector>


namespace collection {

class Count;


/** 
 * Counter class.
 * 
 * Implemented on top of `std::unordered_map` to store and handle multiple counters.
 * Inspired by https://docs.python.org/3/library/collections.html#collections.Counter written in *python*.
 * 
 * #### Example
 * 
 * ```
 * collection::Counter counter({"koala", "panda", "firefox"});
 * counter["koala"]++;
 * counter["panda"]--;
 * counter["firefox"] += 4;
 *
 * for (const auto& [element, count]: counter) {
 *     std::cout << "* \"" << element << "\" count: " << count.value() << std::endl;
 * }
 * ```
 */
template<class T>
class Counter {
    typedef typename std::unordered_map<T, Count>::size_type size_type;
    typedef typename std::unordered_map<T, Count>::const_iterator const_iterator;

    public:
        /** Constructs the Counter. */
        Counter() = default;

        /** Constructs the Counter from a `std::initializer_list`. */
        Counter(const std::initializer_list<T>& init) {
            for (const T& element: init) {
                ++counts_[element];
            }
        }

        /** Constructs the Counter from a `std::unordered_map`. */
        Counter(const std::unordered_map<T, Count>& counts) {
            for (const auto & [element, count]: counts) {
                counts_[element] = count;
            }
        }

        /** Constructs the Counter from a `std::vector`. */
        Counter(const std::vector<T>& elements) {
            for (const T& element: elements) {
                ++counts_[element];
            }
        }

        Counter(const Counter&) = default;
        Counter& operator=(const Counter&) = default;


        /** Returns an iterator to the beginning. */
        const_iterator begin() const noexcept {
            return counts_.begin();
        }

        /** Returns an iterator to the end. */
        const_iterator end() const noexcept {
            return counts_.end();
        }

        
        /** 
         * Returns the specified element.
         * If the element does not exists, it gets created with an empty count.
         */
        Count& operator[](const T& element) {
            if (counts_.find(element) == counts_.end()) {
                counts_[element] = {};
            }
            return counts_[element];
        }

        /** Returns the number of elements. */
        size_type size() const {
            return std::count_if(counts_.begin(), 
                counts_.end(), 
                [](const auto& pair){ return pair.second.value() >= 1; }
            );
        }

        /** Returns a list of the n most common elements and their count as a new Counter container. */
        Counter<T> most_common(size_t n = 1) {
            std::unordered_map<T, Count> mostCommon;

            std::copy_if(counts_.begin(), 
                counts_.end(), 
                std::inserter(mostCommon, mostCommon.end()), 
                [n](const auto & pair){ return pair.second.value() >= n; }
            );

            return Counter<T>{mostCommon};
        }

        /** Elements counts are added from another Counter elements counts. */
        Counter<T>& operator+=(const Counter<T>& other) {
            for (const auto& [element, count]: other.counts_) {
                counts_[element] += count;
            }
            return *this;
        }

        /** Elements counts are subtracted from another Counter elements counts. */
        Counter<T>& operator-=(const Counter<T>& other) {
            for (const auto& [element, count]: other.counts_) {
                counts_[element] -= count;
            }
            return *this;
        }

    private:

        std::unordered_map<T, Count> counts_;
};


/** 
 * Count class.
 * 
 * Enclose a `size_t` value in order to secure the counts operations (such as protect from negative values).
 * 
 */

class Count {
    public:
        Count(): count_(0) {}
        Count(size_t n): count_(n) {}

        Count(const Count&) = default;
        Count& operator=(const Count&) = default;

        size_t value() const {
            return count_;
        }

        // prefix increment
        Count& operator++() {
            ++count_;
            return *this;
        }
    
        // postfix increment
        Count operator++(int) {
            Count old = *this;
            operator++();
            return old;
        }

        Count& operator+=(const Count& other) {
            return operator+=(other.value());
        }

        Count& operator+=(size_t increment) {
            count_ += increment;
            return *this;
        }

        // prefix decrement
        Count& operator--() {
            if (count_ > 0) {
                --count_;
            }
            return *this;
        }
    
        // postfix decrement
        Count operator--(int) {
            Count old = *this;
            operator--();
            return old;
        }


        Count& operator-=(const Count& other) {
            return operator-=(other.value());
        }

        Count& operator-=(size_t decrement) {
            if (decrement >= count_) {
                count_ = 0;
            } else {
                count_ -= decrement;
            }
            return *this;
        }

        operator const size_t() {
            return value();
        }


    private:
        size_t count_;
};


} // Collection
