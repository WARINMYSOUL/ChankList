///@brief Требуется реализовать ChunkList для хедера
///Работает как std::list
///Выделяет память под элементы блоками, размером под N элементов (параметр шаблона).
///При вставке пытается вставить в существующие блоки, если не может, добавляет новый.
///При удалении элемента, если блок становится пустой удаляет его.
///Иначе сдвигает все элементы внутри блока. То есть каждый чанк может быть заполнен не полностью.

#pragma once
#include <iterator>
#include <memory>

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
        /// оператор <=> пригодится
    };

    template <typename ValueType>
    class ChunkList_const_iterator {
        /// Не следует давать не константные ссылки на значение
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
        /// operator<=> will be handy
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

        /// @brief Конструктор по умолчанию. Создает пустой контейнер с
        /// аллокатором, сконструированным по умолчанию.
        ChunkList();

        /// @brief Создает пустой контейнер с заданным аллокатором
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        explicit ChunkList(const Allocator& alloc);

        /// @brief Конструирует контейнер с count-копиями элементов со значением
        /// и с заданным аллокатором
        /// @param count размер контейнера
        /// @param value значение, которым инициализируются элементы контейнера
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        ChunkList(size_type count, const T& value, const Allocator& alloc = Allocator());

        /// @brief Конструирует контейнер с подсчетом вставленных по умолчанию экземпляров
        /// T. Копии не создаются.
        /// @param count размер контейнера
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        explicit ChunkList(size_type count, const Allocator& alloc = Allocator());

        /// @brief Конструирует контейнер с содержимым диапазона [first,
        /// last).
        /// @tparam InputIt Входной итератор
        /// @param first, last 	диапазон, из которого нужно скопировать элементы
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        template <class InputIt>
        ChunkList(InputIt first, InputIt last, const Allocator& alloc = Allocator());

        /// @brief Конструктор копий. Конструирует контейнер с копией
        /// содержимое других.
        /// @param other другой контейнер, который будет использоваться в качестве источника для инициализации
        /// элементов контейнера
        ChunkList(const ChunkList& other);

        /// @brief Конструирует контейнер с копией содержимого other,
        /// используя alloc в качестве аллокатора.
        /// @param other другой контейнер, который будет использоваться в качестве источника для инициализации
        /// элементы контейнера с
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        ChunkList(const ChunkList& other, const Allocator& alloc);

        /**
         * @brief Конструктор перемещения.
         *
         * Конструирует контейнер с содержимым другого, используя семантику перемещения.
         * Аллокатор получается путем перемещения-конструкции из аллокатора, принадлежащего
         * other.
         *
         * @param other другой контейнер, который будет использоваться в качестве источника для инициализации
         * элементов контейнера
         */
        ChunkList(ChunkList&& other);

        /**
         * @brief Конструктор перемещения с расширенным аллокатором.
         * Используя alloc в качестве аллокатора для нового контейнера, перемещаем его содержимое
         * из другого; if alloc != other.get_allocator(), это приводит к перемещению
         * перемещение по элементам.
         *
         * @param other другой контейнер, который будет использоваться в качестве источника для инициализации
         * элементы контейнера с
         * @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
         */
        ChunkList(ChunkList&& other, const Allocator& alloc);

        /// @brief Создает контейнер с содержимым списка инициализатора
        /// init.
        /// @param init список инициализаторов для инициализации элементов контейнера
        /// с
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        ChunkList(std::initializer_list<T> init, const Allocator& alloc = Allocator());

        /// @brief Уничтожает список ChunkList.
        ~ChunkList();

        /// @brief Оператор присвоения копий. Заменяет содержимое копией
        /// содержимое других.
        /// @param other другой контейнер для использования в качестве источника данных
        /// @return *this
        ChunkList& operator=(const ChunkList& other);

        /**
         * Оператор присвоения перемещения.
         *
         * Заменяет содержимое контейнера other на содержимое контейнера other с использованием семантики перемещения.
         * (т. е. данные из other перемещаются в этот контейнер).
         * После этого other находится в допустимом, но неопределенном состоянии.
         *
         * @param other другой контейнер для использования в качестве источника данных
         * @return *this
         */
        ChunkList& operator=(ChunkList&& other);

        /// @brief Заменяет содержимое на содержимое, указанное в списке инициализаторов
        /// ilist.
        /// @param ilist
        /// @return this
        ChunkList& operator=(std::initializer_list<T> ilist);

        /// @brief Заменяет содержимое счетчиком копий значения
        /// @param count
        /// @param value
        void assign(size_type count, const T& value);

        /// @brief Заменяет содержимое копиями содержимого в диапазоне [first,
        /// last).
        /// @tparam InputIt
        /// @param first
        /// @param last
        template <class InputIt>
        void assign(InputIt first, InputIt last);

        /// @brief Заменяет содержимое элементами из списка инициализаторов
        /// ilis
        /// @param ilist
        void assign(std::initializer_list<T> ilist);

        /// @brief Возвращает аллокатор, связанный с контейнером.
        /// @return Связанный аллокатор.
        allocator_type get_allocator() const noexcept;

        /// ДОСТУП К ЭЛЕМЕНТУ

        /// @brief Возвращает ссылку на элемент в указанном месте pos, с
        /// проверкой границ. Если pos не находится в пределах диапазона контейнера, то
        /// будет выброшено исключение типа std::out_of_range.
        /// @param pos позиция возвращаемого элемента
        /// @return Ссылка на запрашиваемый элемент.
        /// @throw std::out_of_range
        reference at(size_type pos);

        /// @brief Возвращает const ссылку на элемент в указанном месте pos,
        /// с проверкой границ. Если pos не находится в пределах диапазона контейнера, то
        /// будет выброшено исключение типа std::out_of_range..
        /// @param pos позиция возвращаемого элемента
        /// @return Ссылка на запрашиваемый элемент.
        /// @throw std::out_of_range
        const_reference at(size_type pos) const;

        /// @brief Возвращает ссылку на элемент в указанном месте pos. Никакой
        /// проверка границ не выполняется.
        /// @param pos позиция возвращаемого элемента
        /// @return Ссылка на запрашиваемый элемент.
        reference operator[](size_type pos);

        /// @brief Возвращает const ссылку на элемент в указанном месте pos.
        /// Проверка границ не выполняется.
        /// @param pos позиция возвращаемого элемента
        /// @return Const Ссылка на запрашиваемый элемент.
        const_reference operator[](size_type pos) const;

        /// @brief Возвращает ссылку на первый элемент в контейнере.
        /// Вызов front для пустого контейнера не определен.
        /// Ссылка на первый элемент
        reference front();

        /// @brief Возвращает const ссылку на первый элемент в контейнере.
        /// Вызов front для пустого контейнера не определен.
        /// @return Const ссылка на первый элемент
        const_reference front() const;

        /// @brief Возвращает ссылку на последний элемент в контейнере.
        /// Обратный вызов пустого контейнера приводит к неопределенному поведению.
        /// @return Ссылка на последний элемент.
        reference back();

        /// @brief Возвращает const ссылку на последний элемент в контейнере.
        /// Обратный вызов при пустом контейнере приводит к неопределенному поведению.
        /// @return Const Ссылка на последний элемент.
        const_reference back() const;

        /// ИТЕРАТОРЫ

        /// @brief Возвращает итератор к первому элементу списка ChunkList.
        /// Если ChunkList пуст, возвращаемый итератор будет равен end().
        /// @return Итератор к первому элементу.
        iterator begin() noexcept;

        /// @brief Возвращает итератор к первому элементу списка ChunkList.
        /// Если ChunkList пуст, возвращаемый итератор будет равен end().
        /// @return Итератор к первому элементу.
        const_iterator begin() const noexcept;

        /// @brief То же самое, что и begin()
        const_iterator cbegin() const noexcept;

        /// @brief Возвращает итератор к элементу, следующему за последним элементом
        /// списка ChunkList. Этот элемент выступает в качестве заполнителя; попытка доступа к нему
        /// приводит к неопределенному поведению.
        /// @return Итератор к элементу, следующему за последним элементом.
        iterator end() noexcept;

        /// @brief Возвращает постоянный итератор к элементу, следующему за последним
        /// элементом списка ChunkList. Этот элемент выступает в качестве заполнителя; попытка
        /// получить к нему доступ приводит к неопределенному поведению.
        /// @return Постоянный итератор к элементу, следующему за последним элементом.
        const_iterator end() const noexcept;

        /// @brief То же самое, что и end()
        const_iterator cend() const noexcept;

        /// ВМЕСТИМОСТЬ

        /// @brief Проверяет, нет ли в контейнере элементов.
        /// @return  true, если контейнер пуст, false в противном случае
        bool empty() const noexcept;

        /// @brief Возвращает количество элементов в контейнере
        /// @return Количество элементов в контейнере.
        size_type size() const noexcept;

        /// @brief Возвращает максимальное количество элементов, которые может содержать контейнер
        /// задержка из-за ограничений системы или библиотеки
        /// @return Максимальное количество элементов.
        size_type max_size() const noexcept;

        /// @brief Запрашивает удаление неиспользуемой памяти.
        /// Это необязательный запрос для уменьшения использования памяти без изменения
        /// размера последовательности. Все итераторы и ссылки аннулируются.
        /// Прошедший конец итератор также аннулируется.
        void shrink_to_fit();

        /// МОДИФИКАТОРЫ

        /// @brief Стирает все элементы из контейнера.
        /// Проверяет все ссылки, указатели или итераторы, ссылающиеся на содержащиеся в контейнере
        /// элементы. Любые итераторы, находящиеся в конце, также аннулируются.
        void clear() noexcept;

        /// @brief Вставляет значение перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param value значение элемента для вставки
        /// @return указывающий на вставленное значение.
        iterator insert(const_iterator pos, const T& value);

        /// @brief Вставляет значение перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param value значение элемента для вставки
        /// @return Итератор, указывающий на вставленное значение.
        iterator insert(const_iterator pos, T&& value);

        /// @brief Вставляет счетные копии значения перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param count количество элементов для вставки
        /// @param value значение элемента для вставки
        /// @return Итератор, указывающий на первый вставленный элемент, или pos, если count
        /// == 0.
        iterator insert(const_iterator pos, size_type count, const T& value);

        /// @brief Вставляет элементы из диапазона [first, last) перед pos.
        /// @tparam InputIt  Входной итератор InputIt
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param first,last диапазон элементов для вставки, не могут быть итераторами в
        /// контейнера, для которого вызывается вставка
        /// @return Итератор, указывающий на первый вставленный элемент, или pos, если first
        /// == last.
        template <class InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last);

        /// @brief Вставляет элементы из списка инициализаторов перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param ilist список инициализаторов, из которого вставляются значения
        /// @return Итератор, указывающий на первый вставленный элемент, или pos, если ilist
        /// пуст.
        iterator insert(const_iterator pos, std::initializer_list<T> ilist);

        /// @brief Вставляет новый элемент в контейнер непосредственно перед pos.
        /// @param pos итератор, перед которым будет построен новый элемент
        /// @param ...args аргументы для передачи конструктору элемента
        /// @return указывающий на помещенный элемент.
        template <class... Args>
        iterator emplace(const_iterator pos, Args&&... args);

        /// @brief Удаляет элемент в позиции pos.
        /// @param pos итератор к удаляемому элементу
        /// @return Итератор, следующий за последним удаленным элементом.
        iterator erase(const_iterator pos);

        /// @brief Удаляет элементы в диапазоне [first, last).
        /// @param first,last диапазон удаляемых элементов
        /// @return следующий за последним удаленным элементом.
        iterator erase(const_iterator first, const_iterator last);

        /// @brief Добавляет заданное значение элемента в конец контейнера.
        /// Новый элемент инициализируется как копия value.
        /// @param value значение элемента для добавления
        void push_back(const T& value);

        /// @brief Добавляет заданное значение элемента в конец контейнера.
        /// Значение перемещается в новый элемент.
        /// @param value value значение элемента для добавления
        void push_back(T&& value);

        /// @brief Добавляет новый элемент в конец контейнера.
        /// @param ...args  аргументы для передачи в конструктор элемента
        /// @return Ссылка на вставленный элемент.
        template <class... Args>
        reference emplace_back(Args&&... args);

        /// @brief Удаляет последний элемент контейнера.
        void pop_back();

        /// @brief Добавляет значение заданного элемента в начало контейнера.
        /// @param value значение элемента, который нужно добавить
        void push_front(const T& value);

        /// @brief Добавляет значение заданного элемента в начало контейнера.
        /// @param value moved значение элемента для добавления
        void push_front(T&& value);

        /// @brief Вставляет новый элемент в начало контейнера.
        /// @param ...args аргументы для передачи в конструктор элемента
        /// @return Ссылка на вставленный элемент.
        template <class... Args>
        reference emplace_front(Args&&... args);

        /// @brief Удаляет первый элемент контейнера.
        void pop_front();

        /// @brief Изменяет размер контейнера, чтобы он содержал count элементов.
        /// Если текущий размер больше count, контейнер уменьшается до его
        /// первых элементов count. Если текущий размер меньше count, дополнительные
        /// вставляемые по умолчанию элементы добавляются
        /// @param count новый размер контейнера
        void resize(size_type count);

        /// @brief Изменяет размер контейнера, чтобы он содержал count элементов.
        /// Если текущий размер больше count, контейнер уменьшается до его
        /// первых элементов count. Если текущий размер меньше count, дополнительные
        /// добавляются дополнительные копии значения.
        /// @param count новый размер контейнера
        /// @param value значение, которым инициализируются новые элементы
        void resize(size_type count, const value_type& value);

        /// @brief Обменивает содержимое контейнера на содержимое других контейнеров.
        /// Не вызывает никаких операций перемещения, копирования или замены отдельных элементов.
        /// Все итераторы и ссылки остаются в силе. Прошедший конец итератор
        /// аннулируется.
        /// @param other container to exchange the contents with
        void swap(ChunkList& other);

        /// СРАВНЕНИЯ

        /// @brief Проверяет, одинаково ли содержимое lhs и rhs.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        template <class U, class Alloc>
        friend bool operator==(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        /// @brief Проверяет, не равно ли содержимое lhs и rhs.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        template <class U, class Alloc>
        friend bool operator!=(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        template <class U, class Alloc>
        friend bool operator>(const ChunkList<U, Alloc>& lhs, const ChunkList<U, Alloc>& rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        template <class U, class Alloc>
        friend bool operator<(const ChunkList<U, Alloc>& lhs, const ChunkList<U, Alloc>& rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        template <class U, class Alloc>
        friend bool operator>=(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        template <class U, class Alloc>
        friend bool operator<=(const ChunkList<U, Alloc>& lhs,
                               const ChunkList<U, Alloc>& rhs);

        // оператор <=> пригодится
    };

/// ФУНКЦИИ, НЕ ЯВЛЯЮЩИЕСЯ ЧЛЕНАМИ

/// @brief Меняет местами содержимое lhs и rhs.
/// @param lhs,rhs контейнеры, содержимое которых нужно поменять местами
    template <class T, class Alloc>
    void swap(ChunkList<T, Alloc>& lhs, ChunkList<T, Alloc>& rhs);

/// @brief Стирает из контейнера все элементы, которые сравниваются с value.
/// @param c контейнер, из которого нужно стереть
/// @param value значение, которое должно быть удалено
/// @return Количество стертых элементов.
    template <class T, class Alloc, class U>
    typename ChunkList<T, Alloc>::size_type erase(ChunkList<T, Alloc>& c, const U& value);

/// @brief Стирает из контейнера все элементы, которые сравниваются с value.
/// @param c контейнер, из которого нужно стереть
/// @param pred унарный предикат, возвращающий true, если элемент должен быть /// стерт.
/// удален.
/// @return Количество стертых элементов.
    template <class T, class Alloc, class Pred>
    typename ChunkList<T, Alloc>::size_type erase_if(ChunkList<T, Alloc>& c, Pred pred);
}
/// пространство имен fefu_laboratory_two