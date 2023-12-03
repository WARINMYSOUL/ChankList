#include "ChunkList.h"

namespace fefu_laboratory_two {

    template <typename T>
    class Allocator {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using const_pointer = const T*;
        using reference = T&;
        using const_reference = const T&;

        Allocator() noexcept;

        Allocator(const Allocator& other) noexcept;

        template <class U>
        Allocator(const Allocator<U>& other) noexcept;

        ~Allocator();

        pointer allocate(size_type);

        void deallocate(pointer p, size_type n) noexcept;
    };

    template <typename ValueType>
    class ChunkList_iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = ValueType;
        using difference_type = std::ptrdiff_t;
        using pointer = ValueType*;
        using reference = ValueType&;

        ChunkList_iterator() noexcept;

        ChunkList_iterator(const ChunkList_iterator& other) noexcept;

        ChunkList_iterator& operator=(const ChunkList_iterator&);

        ~ChunkList_iterator();

        friend void swap(ChunkList_iterator<ValueType>&, ChunkList_iterator<ValueType>&);

        friend bool operator==(const ChunkList_iterator<ValueType>&,
                               const ChunkList_iterator<ValueType>&);
        friend bool operator!=(const ChunkList_iterator<ValueType>&,
                               const ChunkList_iterator<ValueType>&);

        reference operator*() const;
        pointer operator->() const;

        ChunkList_iterator& operator++();
        ChunkList_iterator operator++(int);

        ChunkList_iterator& operator--();
        ChunkList_iterator operator--(int);

        ChunkList_iterator operator+(const difference_type&) const;
        ChunkList_iterator& operator+=(const difference_type&);

        ChunkList_iterator operator-(const difference_type&) const;
        ChunkList_iterator& operator-=(const difference_type&);

        difference_type operator-(const ChunkList_iterator&) const;

        reference operator[](const difference_type&);

        friend bool operator<(const ChunkList_iterator<ValueType>&,
                              const ChunkList_iterator<ValueType>&);
        friend bool operator<=(const ChunkList_iterator<ValueType>&,
                               const ChunkList_iterator<ValueType>&);
        friend bool operator>(const ChunkList_iterator<ValueType>&,
                              const ChunkList_iterator<ValueType>&);
        friend bool operator>=(const ChunkList_iterator<ValueType>&,
                               const ChunkList_iterator<ValueType>&);
    };

    template <typename ValueType>
    class ChunkList_const_iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = ValueType;
        using difference_type = std::ptrdiff_t;
        using pointer = const ValueType*;
        using reference = const ValueType&;

        ChunkList_const_iterator() noexcept;
        ChunkList_const_iterator(const ChunkList_const_iterator&) noexcept;
        ChunkList_const_iterator(const ChunkList_iterator<ValueType>&) noexcept;

        ChunkList_const_iterator& operator=(const ChunkList_const_iterator&);
        ChunkList_const_iterator& operator=(const ChunkList_iterator<ValueType>&);

        ~ChunkList_const_iterator();

        friend void swap(ChunkList_const_iterator<ValueType>&,
                         ChunkList_const_iterator<ValueType>&);

        friend bool operator==(const ChunkList_const_iterator<ValueType>&,
                               const ChunkList_const_iterator<ValueType>&);
        friend bool operator!=(const ChunkList_const_iterator<ValueType>&,
                               const ChunkList_const_iterator<ValueType>&);

        reference operator*() const;
        pointer operator->() const;

        ChunkList_const_iterator& operator++();
        ChunkList_const_iterator operator++(int);

        ChunkList_const_iterator& operator--();
        ChunkList_const_iterator operator--(int);

        ChunkList_const_iterator operator+(const difference_type&) const;
        ChunkList_const_iterator& operator+=(const difference_type&);

        ChunkList_const_iterator operator-(const difference_type&) const;
        ChunkList_const_iterator& operator-=(const difference_type&);

        difference_type operator-(const ChunkList_const_iterator&) const;

        reference operator[](const difference_type&);

        friend bool operator<(const ChunkList_const_iterator<ValueType>&,
                              const ChunkList_const_iterator<ValueType>&);
        friend bool operator<=(const ChunkList_const_iterator<ValueType>&,
                               const ChunkList_const_iterator<ValueType>&);
        friend bool operator>(const ChunkList_const_iterator<ValueType>&,
                              const ChunkList_const_iterator<ValueType>&);
        friend bool operator>=(const ChunkList_const_iterator<ValueType>&,
                               const ChunkList_const_iterator<ValueType>&);
    };

    template <typename T, int N, typename Allocator = Allocator<T>>
    class ChunkList {
    public:
        using value_type = T;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        using iterator = ChunkList_iterator<value_type>;
        using const_iterator = ChunkList_const_iterator<value_type>;

        ChunkList();

        explicit ChunkList(const Allocator& alloc);

        ChunkList(size_type count, const T& value, const Allocator& alloc = Allocator());

        explicit ChunkList(size_type count, const Allocator& alloc = Allocator());

        template <class InputIt>
        ChunkList(InputIt first, InputIt last, const Allocator& alloc = Allocator());

        ChunkList(const ChunkList& other);

        ChunkList(const ChunkList& other, const Allocator& alloc);

        ChunkList(ChunkList&& other);

        ChunkList(ChunkList&& other, const Allocator& alloc);

        ChunkList(std::initializer_list<T> init, const Allocator& alloc = Allocator());

        ~ChunkList();

        ChunkList& operator=(const ChunkList& other);

        ChunkList& operator=(ChunkList&& other);

        ChunkList& operator=(std::initializer_list<T> ilist);

        void assign(size_type count, const T& value);

        template <class InputIt>
        void assign(InputIt first, InputIt last);

        void assign(std::initializer_list<T> ilist);

        allocator_type get_allocator() const noexcept;

        reference at(size_type pos);

        const_reference at(size_type pos) const;

        reference operator[](size_type pos);

        const_reference operator[](size_type pos) const;

        reference front();

        const_reference front() const;

        reference back();

        const_reference back() const;

        iterator begin() noexcept;

        const_iterator begin() const noexcept;

        const_iterator cbegin() const noexcept;

        iterator end() noexcept;

        const_iterator end() const noexcept;

        const_iterator cend() const noexcept;

        bool empty() const noexcept;

        size_type size() const noexcept;

        size_type max_size() const noexcept;

        void shrink_to_fit();

        void clear() noexcept;

        iterator insert(const_iterator pos, const T& value);

        iterator insert(const_iterator pos, T&& value);

        iterator insert(const_iterator pos, size_type count, const T& value);

        template <class InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last);

        iterator insert(const_iterator pos, std::initializer_list<T> ilist);

        template <class... Args>
        iterator emplace(const_iterator pos, Args&&... args);

        iterator erase(const_iterator pos);

        iterator erase(const_iterator first, const_iterator last);

        void push_back(const T& value);

        void push_back(T&& value);

        template <class... Args>
        reference emplace_back(Args&&... args);

        void pop_back();

        void push_front(const T& value);

        void push_front(T&& value);

        template <class... Args>
        reference emplace_front(Args&&... args);

        void pop_front();

        void resize(size_type count);

        void resize(size_type count, const value_type& value);

        void swap(ChunkList& other);

        template <class U, class Alloc>
        friend bool operator==(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        template <class U, class Alloc>
        friend bool operator!=(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        template <class U, class Alloc>
        friend bool operator>(const ChunkList<U, Alloc>& lhs, const ChunkList<U, Alloc>& rhs);

        template <class U, class Alloc>
        friend bool operator<(const ChunkList<U, Alloc>& lhs, const ChunkList<U, Alloc>& rhs);

        template <class U, class Alloc>
        friend bool operator>=(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        template <class U, class Alloc>
        friend bool operator<=(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);
    };

    template <class T, class Alloc>
    void swap(ChunkList<T, Alloc>& lhs, ChunkList<T, Alloc>& rhs);

    template <class T, class Alloc, class U>
    typename ChunkList<T, Alloc>::size_type erase(ChunkList<T, Alloc>& c, const U& value);

    template <class T, class Alloc, class Pred>
    typename ChunkList<T, Alloc>::size_type erase_if(ChunkList<T, Alloc>& c, Pred pred);
}