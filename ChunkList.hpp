#pragma once

#include <iterator>
#include <memory>
#include <list>

namespace fefu_laboratory_two {

    template<typename T>
    class Allocator {
    public:
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using const_pointer = const T *;
        using reference = T &;
        using const_reference = const T &;

        // Реализация конструктора по умолчанию
        Allocator() noexcept;

        // Реализация конструктора копирования
        Allocator(const Allocator &other) noexcept;

        // Реализация конструктора копирования от другого типа
        template<class U>
        explicit Allocator(const Allocator<U> &other) noexcept;

        // Реализация деструктора
        ~Allocator();

        // Реализация выделения памяти
        pointer allocate(size_type n);

        // Реализация освобождения памяти
        void deallocate(pointer p, size_type n) noexcept;
    };

    template<typename ValueType>
    class ChunkList_iterator {
    private:
        ValueType* iterator = nullptr;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = ValueType;
        using difference_type = std::ptrdiff_t;
        using pointer = ValueType *;
        using reference = ValueType &;

        // Реализация конструктора по умолчанию
        ChunkList_iterator() noexcept;

        // Реализация конструктора копирования
        ChunkList_iterator(const ChunkList_iterator &other) noexcept;

        // Реализация оператора присваивания
        ChunkList_iterator &operator=(const ChunkList_iterator &);

        // Реализация деструктора
        ~ChunkList_iterator();

        // Реализация функции swap
        friend void swap(ChunkList_iterator<ValueType> &lhs, ChunkList_iterator<ValueType> &rhs) {

        }

        // Реализация оператора ==
        friend bool operator==(const ChunkList_iterator<ValueType> &lhs,
                               const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator == rhs.iterator;
        }

        // Реализация оператора !=
        friend bool operator!=(const ChunkList_iterator<ValueType> &lhs,
                               const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator != rhs.iterator;
        }

        // Реализация оператора разыменования *
        reference operator*() const;

        // Реализация оператора ->
        pointer operator->() const;

        // Реализация оператора префиксного инкремента
        ChunkList_iterator &operator++();

        // Реализация оператора постфиксного инкремента
        ChunkList_iterator operator++(int);

        // Реализация оператора префиксного декремента
        ChunkList_iterator &operator--();

        // Реализация оператора постфиксного декремента
        ChunkList_iterator operator--(int);

        // Реализация оператора сложения с числом
        ChunkList_iterator operator+(const difference_type &) const;

        // Реализация оператора присваивания сложения с числом
        ChunkList_iterator &operator+=(const difference_type &);

        // Реализация оператора вычитания из числа
        ChunkList_iterator operator-(const difference_type &) const;

        // Реализация оператора присваивания вычитания из числа
        ChunkList_iterator &operator-=(const difference_type &);

        // Реализация оператора вычитания двух итераторов
        difference_type operator-(const ChunkList_iterator &) const;

        // Реализация оператора индексации
        reference operator[](const difference_type &);

        // Реализация оператора <
        friend bool operator<(const ChunkList_iterator<ValueType> &lhs,
                               const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator < rhs.iterator;
        }

        // Реализация оператора <=
        friend bool operator<=(const ChunkList_iterator<ValueType> &lhs,
                               const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator <= rhs.iterator;
        }

        // Реализация оператора >
        friend bool operator>(const ChunkList_iterator<ValueType> &lhs,
                               const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator > rhs.iterator;
        }

        // Реализация оператора >=
        friend bool operator>=(const ChunkList_iterator<ValueType> &lhs,
                              const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator >= rhs.iterator;
        }

        // Реализация оператора <=>
        friend bool operator<=>(const ChunkList_iterator<ValueType> &lhs,
                              const ChunkList_iterator<ValueType> &rhs) {
            return lhs.iterator <=> rhs.iterator;
        }
    };

    template<typename ValueType>
    class ChunkList_const_iterator {
    private:
        const ValueType* iterator = nullptr;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = ValueType;
        using difference_type = std::ptrdiff_t;
        using pointer = const ValueType *;
        using reference = const ValueType &;

        // Реализация конструктора от обычного итератора
        ChunkList_const_iterator() noexcept;

        // Реализация конструктора копирования
        ChunkList_const_iterator(const ChunkList_const_iterator &) noexcept;

        // Реализация конструктора от обычного итератора
        ChunkList_const_iterator(const ChunkList_iterator<ValueType> &) noexcept;

        // Реализация оператора присваивания
        ChunkList_const_iterator &operator=(const ChunkList_const_iterator &);

        // Реализация оператора присваивания от обычного итератора
        ChunkList_const_iterator &operator=(const ChunkList_iterator<ValueType> &);

        // Реализация деструктора
        ~ChunkList_const_iterator();

        // Реализация функции swap
        friend void swap(ChunkList_const_iterator<ValueType> &lhs,
                         ChunkList_const_iterator<ValueType> &rhs);

        // Реализация оператора ==
        friend bool operator==(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator == rhs.iterator;
        }

        // Реализация оператора !=
        friend bool operator!=(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator != rhs.iterator;
        }

        // Реализация оператора разыменования *
        reference operator*() const;

        // Реализация оператора ->
        pointer operator->() const;

        // Реализация оператора префиксного инкремента
        ChunkList_const_iterator &operator++();

        // Реализация оператора постфиксного инкремента
        ChunkList_const_iterator operator++(int);

        // Реализация оператора префиксного декремента
        ChunkList_const_iterator &operator--();

        // Реализация оператора постфиксного декремента
        ChunkList_const_iterator operator--(int);

        // Реализация оператора сложения с числом
        ChunkList_const_iterator operator+(const difference_type &) const;

        // Реализация оператора присваивания сложения с числом
        ChunkList_const_iterator &operator+=(const difference_type &);

        // Реализация оператора вычитания из числа
        ChunkList_const_iterator operator-(const difference_type &) const;

        // Реализация оператора присваивания вычитания из числа
        ChunkList_const_iterator &operator-=(const difference_type &);

        // Реализация оператора вычитания двух итераторов
        difference_type operator-(const ChunkList_const_iterator &) const;

        // Реализация оператора индексации
        reference operator[](const difference_type &);

        // Реализация оператора <
        friend bool operator<(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator < rhs.iterator;
        }

        // Реализация оператора <=
        friend bool operator<=(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator <= rhs.iterator;
        }

        // Реализация оператора >
        friend bool operator>(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator > rhs.iterator;
        }

        // Реализация оператора >=
        friend bool operator>=(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator >= rhs.iterator;
        }

        // Реализация оператора <=>
        friend bool operator<=>(const ChunkList_const_iterator<ValueType> &lhs,
                               const ChunkList_const_iterator<ValueType> &rhs) {
            return lhs.iterator <=> rhs.iterator;
        }
    };

    template<typename T, int N, typename Allocator = Allocator<T>>
    class ChunkList {
    public:
        using value_type = T;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type &;
        using const_reference = const value_type &;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
        using iterator = ChunkList_iterator<value_type>;
        using const_iterator = ChunkList_const_iterator<value_type>;


        /// @brief Конструктор по умолчанию. Создает пустой контейнер с
        /// аллокатором, сконструированным по умолчанию.
        // Конструктор по умолчанию
        ChunkList();

        /// @brief Создает пустой контейнер с заданным аллокатором
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        // Конструктор с аллокатором
        explicit ChunkList(const Allocator &alloc);

        /// @brief Конструирует контейнер с count-копиями элементов со значением
        /// и с заданным аллокатором
        /// @param count размер контейнера
        /// @param value значение, которым инициализируются элементы контейнера
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        // Конструктор с count копиями элементов со значением и аллокатором
        ChunkList(size_type count, const T &value, const Allocator &alloc = Allocator());

        /// @brief Конструирует контейнер с подсчетом вставленных по умолчанию экземпляров
        /// T. Копии не создаются.
        /// @param count размер контейнера
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        // Конструктор с count экземплярами T, вставленными по умолчанию
        explicit ChunkList(size_type count, const Allocator &alloc = Allocator());

        /// @brief Конструирует контейнер с содержимым диапазона [first,
        /// last).
        /// @tparam InputIt Входной итератор
        /// @param first, last 	диапазон, из которого нужно скопировать элементы
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        // Конструктор с содержимым диапазона [first, last)
        template<class InputIt>
        ChunkList(InputIt first, InputIt last, const Allocator &alloc = Allocator());

        /// @brief Конструктор копий. Конструирует контейнер с копией
        /// содержимое других.
        /// @param other другой контейнер, который будет использоваться в качестве источника для инициализации
        /// элементов контейнера
        // Конструктор копирования
        ChunkList(const ChunkList &other);

        /// @brief Конструирует контейнер с копией содержимого other,
        /// используя alloc в качестве аллокатора.
        /// @param other другой контейнер, который будет использоваться в качестве источника для инициализации
        /// элементы контейнера с
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        // Конструктор копирования с аллокатором
        ChunkList(const ChunkList &other, const Allocator &alloc);

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
        // Конструктор перемещения
        ChunkList(ChunkList &&other);

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
        // Расширенный конструктор перемещения с аллокатором
        ChunkList(ChunkList &&other, const Allocator &alloc);

        /// @brief Создает контейнер с содержимым списка инициализатора
        /// init.
        /// @param init список инициализаторов для инициализации элементов контейнера
        /// с
        /// @param alloc аллокатор, который будет использоваться для всех выделений памяти этого контейнера
        // Конструктор с содержимым инициализирующего списка init
        ChunkList(std::initializer_list<T> init, const Allocator &alloc = Allocator());

        /// @brief Уничтожает список ChunkList.
        // Деструктор
        ~ChunkList();

        /// @brief Оператор присвоения копий. Заменяет содержимое копией
        /// содержимое других.
        /// @param other другой контейнер для использования в качестве источника данных
        /// @return *this
        // Оператор присваивания копирования
        ChunkList &operator=(const ChunkList &other);

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
        // Оператор присваивания перемещения
        ChunkList &operator=(ChunkList &&other);

        /// @brief Заменяет содержимое на содержимое, указанное в списке инициализаторов
        /// ilist.
        /// @param ilist
        /// @return this
        // Оператор присваивания инициализирующего списка
        ChunkList &operator=(std::initializer_list<T> ilist);

        /// @brief Заменяет содержимое счетчиком копий значения
        /// @param count
        /// @param value
        // Функция замены содержимого указанным количеством копий значения
        void assign(size_type count, const T &value);

        /// @brief Заменяет содержимое копиями содержимого в диапазоне [first,
        /// last).
        /// @tparam InputIt
        /// @param first
        /// @param last
        // Функция замены содержимого копиями элементов из диапазона [first, last)
        template<class InputIt>
        void assign(InputIt first, InputIt last);

        /// @brief Заменяет содержимое элементами из списка инициализаторов
        /// ilis
        /// @param ilist
        // Функция замены содержимого элементами из инициализирующего списка
        void assign(std::initializer_list<T> ilist);

        /// @brief Возвращает аллокатор, связанный с контейнером.
        /// @return Связанный аллокатор.
        // Возвращает аллокатор, связанный с контейнером
        allocator_type get_allocator() const noexcept;

        /// ДОСТУП К ЭЛЕМЕНТУ

        /// @brief Возвращает ссылку на элемент в указанном месте pos, с
        /// проверкой границ. Если pos не находится в пределах диапазона контейнера, то
        /// будет выброшено исключение типа std::out_of_range.
        /// @param pos позиция возвращаемого элемента
        /// @return Ссылка на запрашиваемый элемент.
        /// @throw std::out_of_range
        // Возвращает ссылку на элемент по указанному местоположению с проверкой границ
        reference at(size_type pos);

        /// @brief Возвращает const ссылку на элемент в указанном месте pos,
        /// с проверкой границ. Если pos не находится в пределах диапазона контейнера, то
        /// будет выброшено исключение типа std::out_of_range..
        /// @param pos позиция возвращаемого элемента
        /// @return Ссылка на запрашиваемый элемент.
        /// @throw std::out_of_range
        // Возвращает константную ссылку на элемент по указанному местоположению с проверкой границ
        const_reference at(size_type pos) const;

        /// @brief Возвращает ссылку на элемент в указанном месте pos. Никакой
        /// проверка границ не выполняется.
        /// @param pos позиция возвращаемого элемента
        /// @return Ссылка на запрашиваемый элемент.
        // Возвращает ссылку на элемент по указанному местоположению без проверки границreference operator[](size_type pos);
        reference operator[](size_type pos);

        /// @brief Возвращает const ссылку на элемент в указанном месте pos.
        /// Проверка границ не выполняется.
        /// @param pos позиция возвращаемого элемента
        /// @return Const Ссылка на запрашиваемый элемент.
        // Возвращает константную ссылку на элемент по указанному местоположению без проверки границ
        const_reference operator[](size_type pos) const;

        /// @brief Возвращает ссылку на первый элемент в контейнере.
        /// Вызов front для пустого контейнера не определен.
        /// Ссылка на первый элемент
        // Возвращает ссылку на первый элемент в контейнере
        reference front();

        /// @brief Возвращает const ссылку на первый элемент в контейнере.
        /// Вызов front для пустого контейнера не определен.
        /// @return Const ссылка на первый элемент
        // Возвращает константную ссылку на первый элемент в контейнере
        const_reference front() const;

        /// @brief Возвращает ссылку на последний элемент в контейнере.
        /// Обратный вызов пустого контейнера приводит к неопределенному поведению.
        /// @return Ссылка на последний элемент.
        // Возвращает ссылку на последний элемент в контейнере
        reference back();

        /// @brief Возвращает const ссылку на последний элемент в контейнере.
        /// Обратный вызов при пустом контейнере приводит к неопределенному поведению.
        /// @return Const Ссылка на последний элемент.
        // Возвращает константную ссылку на последний элемент в контейнере
        const_reference back() const;

        /// ИТЕРАТОРЫ

        /// @brief Возвращает итератор к первому элементу списка ChunkList.
        /// Если ChunkList пуст, возвращаемый итератор будет равен end().
        /// @return Итератор к первому элементу.
        // Возвращает итератор на первый элемент ChunkList
        iterator begin() noexcept;

        /// @brief Возвращает итератор к первому элементу списка ChunkList.
        /// Если ChunkList пуст, возвращаемый итератор будет равен end().
        /// @return Итератор к первому элементу.
        // Возвращает константный итератор на первый элемент ChunkList
        const_iterator begin() const noexcept;

        /// @brief То же самое, что и begin()
        // Возвращает константный итератор на первый элемент ChunkList (аналогично begin())
        const_iterator cbegin() const noexcept;

        /// @brief Возвращает итератор к элементу, следующему за последним элементом
        /// списка ChunkList. Этот элемент выступает в качестве заполнителя; попытка доступа к нему
        /// приводит к неопределенному поведению.
        /// @return Итератор к элементу, следующему за последним элементом.
        // Возвращает итератор на элемент, следующий за последним элементом ChunkList
        iterator end() noexcept;

        /// @brief Возвращает постоянный итератор к элементу, следующему за последним
        /// элементом списка ChunkList. Этот элемент выступает в качестве заполнителя; попытка
        /// получить к нему доступ приводит к неопределенному поведению.
        /// @return Постоянный итератор к элементу, следующему за последним элементом.
        // Возвращает константный итератор на элемент, следующий за последним элементом ChunkList
        const_iterator end() const noexcept;

        /// @brief То же самое, что и end()
        // Возвращает константный итератор на элемент, следующий за последним элементом ChunkList (аналогично end())
        const_iterator cend() const noexcept;

        /// ВМЕСТИМОСТЬ

        /// @brief Проверяет, нет ли в контейнере элементов.
        /// @return  true, если контейнер пуст, false в противном случае
        // Проверяет, пуст ли контейнер
        bool empty() const noexcept;

        /// @brief Возвращает количество элементов в контейнере
        /// @return Количество элементов в контейнере.
        // Возвращает количество элементов в контейнере
        size_type size() const noexcept;

        /// @brief Возвращает максимальное количество элементов, которые может содержать контейнер
        /// задержка из-за ограничений системы или библиотеки
        /// @return Максимальное количество элементов.
        // Возвращает максимальное количество элементов, которые контейнер может содержать
        size_type max_size() const noexcept;

        /// @brief Запрашивает удаление неиспользуемой памяти.
        /// Это необязательный запрос для уменьшения использования памяти без изменения
        /// размера последовательности. Все итераторы и ссылки аннулируются.
        /// Прошедший конец итератор также аннулируется.
        // Запрашивает уменьшение неиспользуемой емкости
        void shrink_to_fit();

        /// МОДИФИКАТОРЫ

        /// @brief Стирает все элементы из контейнера.
        /// Проверяет все ссылки, указатели или итераторы, ссылающиеся на содержащиеся в контейнере
        /// элементы. Любые итераторы, находящиеся в конце, также аннулируются.
        // Очищает контейнер, удаляя все элементы
        void clear() noexcept;

        /// @brief Вставляет значение перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param value значение элемента для вставки
        /// @return указывающий на вставленное значение.
        // Вставляет элемент перед указанным положением pos
        iterator insert(const_iterator pos, const T &value);

        /// @brief Вставляет значение перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param value значение элемента для вставки
        /// @return Итератор, указывающий на вставленное значение.
        // Вставляет элемент перед указанным положением pos
        iterator insert(const_iterator pos, T &&value);

        /// @brief Вставляет счетные копии значения перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param count количество элементов для вставки
        /// @param value значение элемента для вставки
        /// @return Итератор, указывающий на первый вставленный элемент, или pos, если count
        /// == 0.
        // Вставляет count копий значения перед указанным положением pos
        iterator insert(const_iterator pos, size_type count, const T &value);

        /// @brief Вставляет элементы из диапазона [first, last) перед pos.
        /// @tparam InputIt  Входной итератор InputIt
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param first,last диапазон элементов для вставки, не могут быть итераторами в
        /// контейнера, для которого вызывается вставка
        /// @return Итератор, указывающий на первый вставленный элемент, или pos, если first
        /// == last.
        // Вставляет элементы из диапазона [first, last) перед указанным положением pos
        template<class InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last);

        /// @brief Вставляет элементы из списка инициализаторов перед pos.
        /// @param pos итератор, перед которым будет вставлено содержимое.
        /// @param ilist список инициализаторов, из которого вставляются значения
        /// @return Итератор, указывающий на первый вставленный элемент, или pos, если ilist
        /// пуст.
        // Вставляет элементы из инициализирующего списка перед указанным положением pos
        iterator insert(const_iterator pos, std::initializer_list<T> ilist);

        /// @brief Вставляет новый элемент в контейнер непосредственно перед pos.
        /// @param pos итератор, перед которым будет построен новый элемент
        /// @param ...args аргументы для передачи конструктору элемента
        /// @return указывающий на помещенный элемент.
        // Вставляет новый элемент непосредственно перед указанным положением pos
        template<class... Args>
        iterator emplace(const_iterator pos, Args &&... args);

        /// @brief Удаляет элемент в позиции pos.
        /// @param pos итератор к удаляемому элементу
        /// @return Итератор, следующий за последним удаленным элементом.
        // Удаляет элемент в позиции pos
        iterator erase(const_iterator pos);

        /// @brief Удаляет элементы в диапазоне [first, last).
        /// @param first,last диапазон удаляемых элементов
        /// @return следующий за последним удаленным элементом.
        // Удаляет элементы в диапазоне [first, last)
        iterator erase(const_iterator first, const_iterator last);

        /// @brief Добавляет заданное значение элемента в конец контейнера.
        /// Новый элемент инициализируется как копия value.
        /// @param value значение элемента для добавления
        // Добавляет элемент в конец контейнера
        void push_back(const T &value);

        /// @brief Добавляет заданное значение элемента в конец контейнера.
        /// Значение перемещается в новый элемент.
        /// @param value value значение элемента для добавления
        // Добавляет элемент в конец контейнера с использованием std::move
        void push_back(T &&value);

        /// @brief Добавляет новый элемент в конец контейнера.
        /// @param ...args  аргументы для передачи в конструктор элемента
        /// @return Ссылка на вставленный элемент.
        // Вставляет новый элемент в конец контейнера
        template<class... Args>
        reference emplace_back(Args &&... args);

        /// @brief Удаляет последний элемент контейнера.
        // Удаляет последний элемент из контейнера
        void pop_back();

        /// @brief Добавляет значение заданного элемента в начало контейнера.
        /// @param value значение элемента, который нужно добавить
        // Добавляет элемент в начало контейнера
        void push_front(const T &value);

        /// @brief Добавляет значение заданного элемента в начало контейнера.
        /// @param value moved значение элемента для добавления
        // Добавляет элемент в начало контейнера с использованием std::move
        void push_front(T &&value);

        /// @brief Вставляет новый элемент в начало контейнера.
        /// @param ...args аргументы для передачи в конструктор элемента
        /// @return Ссылка на вставленный элемент.
        // Вставляет новый элемент в начало контейнера
        template<class... Args>
        reference emplace_front(Args &&... args);

        /// @brief Удаляет первый элемент контейнера.
        // Удаляет первый элемент из контейнера
        void pop_front();

        /// @brief Изменяет размер контейнера, чтобы он содержал count элементов.
        /// Если текущий размер больше count, контейнер уменьшается до его
        /// первых элементов count. Если текущий размер меньше count, дополнительные
        /// вставляемые по умолчанию элементы добавляются
        /// @param count новый размер контейнера
        // Изменяет размер контейнера, чтобы содержать count элементов
        void resize(size_type count);

        /// @brief Изменяет размер контейнера, чтобы он содержал count элементов.
        /// Если текущий размер больше count, контейнер уменьшается до его
        /// первых элементов count. Если текущий размер меньше count, дополнительные
        /// добавляются дополнительные копии значения.
        /// @param count новый размер контейнера
        /// @param value значение, которым инициализируются новые элементы
        // Изменяет размер контейнера, чтобы содержать count элементов и инициализирует новые элементы значением value
        void resize(size_type count, const value_type &value);

        /// @brief Обменивает содержимое контейнера на содержимое других контейнеров.
        /// Не вызывает никаких операций перемещения, копирования или замены отдельных элементов.
        /// Все итераторы и ссылки остаются в силе. Прошедший конец итератор
        /// аннулируется.
        /// @param other container to exchange the contents with
        // Обменивает содержимое контейнера с содержимым другого контейнера
        void swap(ChunkList &other);

        /// СРАВНЕНИЯ

        /// @brief Проверяет, одинаково ли содержимое lhs и rhs.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        // Оператор сравнения ==
        template<class U, class Alloc>
        friend bool operator==(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);

        /// @brief Проверяет, не равно ли содержимое lhs и rhs.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        // Оператор сравнения !=
        template<class U, class Alloc>
        friend bool operator!=(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        // Оператор сравнения >
        template<class U, class Alloc>
        friend bool operator>(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        // Оператор сравнения <
        template<class U, class Alloc>
        friend bool operator<(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        // Оператор сравнения >=
        template<class U, class Alloc>
        friend bool operator>=(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);

        /// @brief Сравнивает содержимое lhs и rhs лексикографически.
        /// @param lhs,rhs ChunkLists, содержимое которых нужно сравнить
        // Оператор сравнения <=
        template<class U, class Alloc>
        friend bool operator<=(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);

        // Оператор сравнения <=>
        template<class U, class Alloc>
        friend bool operator<=>(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs);
    };

/// ФУНКЦИИ, НЕ ЯВЛЯЮЩИЕСЯ ЧЛЕНАМИ

/// @brief Меняет местами содержимое lhs и rhs.
/// @param lhs,rhs контейнеры, содержимое которых нужно поменять местами
    // Функция обмена содержимым двух контейнеров
    template<class T, class Alloc>
    void swap(ChunkList<T, 0, Alloc> &lhs, ChunkList<T, 0, Alloc> &rhs);

    /// @brief Стирает из контейнера все элементы, которые сравниваются с value.
    /// @param c контейнер, из которого нужно стереть
    /// @param value значение, которое должно быть удалено
    /// @return Количество стертых элементов.
    // Функция удаления всех элементов, равных заданному значению, из контейнера
    template<class T, class Alloc, class U>
    typename ChunkList<T, 0, Alloc>::size_type erase(ChunkList<T, 0, Alloc> &c, const U &value);

    /// @brief Стирает из контейнера все элементы, которые сравниваются с value.
    /// @param c контейнер, из которого нужно стереть
    /// @param pred унарный предикат, возвращающий true, если элемент должен быть /// стерт.
    /// удален.
    /// @return Количество стертых элементов.
    // Функция удаления всех элементов, удовлетворяющих предикату, из контейнера
    template<class T, class Alloc, class Pred>
    typename ChunkList<T, 0, Alloc>::size_type erase_if(ChunkList<T, 0, Alloc> &c, Pred pred);


    // Реализация конструктора по умолчанию
    template<typename T>
    Allocator<T>::Allocator() noexcept {}

    // Реализация конструктора копирования
    template<typename T>
    Allocator<T>::Allocator(const Allocator &other) noexcept {}

    // Реализация конструктора копирования от другого типа
    // Вопрос: чем эта реализация должна отличаться от функции выше?
    template<typename T>
    template<class U>
    Allocator<T>::Allocator(const Allocator<U> &other) noexcept {}

// Реализация деструктора
    template<typename T>
    Allocator<T>::~Allocator() = default;

// Реализация выделения памяти
    template<typename T>
    typename Allocator<T>::pointer Allocator<T>::allocate(size_type n) {
        return static_cast<pointer>(::operator new(n * sizeof(T)));
    }

// Реализация освобождения памяти
    template<typename T>
    void Allocator<T>::deallocate(pointer p, size_type n) noexcept {
        ::operator delete(p);
    }


// Реализация конструктора по умолчанию
    template<typename ValueType>
    ChunkList_iterator<ValueType>::ChunkList_iterator() noexcept = default;

// Реализация конструктора копирования
    template<typename ValueType>
    ChunkList_iterator<ValueType>::ChunkList_iterator(const ChunkList_iterator &other) noexcept {
    }

// Реализация оператора присваивания
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator=(const ChunkList_iterator &other) {

    }

// Реализация деструктора
    template<typename ValueType>
    ChunkList_iterator<ValueType>::~ChunkList_iterator() = default;

// Реализация функции swap
    template<typename ValueType>
    void swap(ChunkList_iterator<ValueType> &lhs, ChunkList_iterator<ValueType> &rhs) {
        swap(lhs.iterator_category, rhs.iterator_category);
        swap(lhs.value_type, rhs.value_type);
        swap(lhs.difference_type, rhs.difference_type);
        swap(lhs.pointer, rhs.pointer);
        swap(lhs.reference, rhs.reference);
    }

    // Реализация оператора разыменования *
    template<typename ValueType>
    typename ChunkList_iterator<ValueType>::reference ChunkList_iterator<ValueType>::operator*() const {

    }

    // Реализация оператора ->
    template<typename ValueType>
    typename ChunkList_iterator<ValueType>::pointer ChunkList_iterator<ValueType>::operator->() const {
        return *this;
    }

    // Реализация оператора префиксного инкремента
    //Вопрос: что здесь должно быть?
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator++() {
        return *this;
    }

    // Реализация оператора постфиксного инкремента
    template<typename ValueType>
    ChunkList_iterator<ValueType> ChunkList_iterator<ValueType>::operator++(int) {
        ChunkList_iterator temp(*this);
        ++(*this);
        return temp;
    }

    // Реализация оператора префиксного декремента
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator--() {
        return *this;
    }

    // Реализация оператора постфиксного декремента
    template<typename ValueType>
    ChunkList_iterator<ValueType> ChunkList_iterator<ValueType>::operator--(int) {
        ChunkList_iterator temp(*this);
        --(*this);
        return temp;
    }

    // Реализация оператора сложения с числом
    template<typename ValueType>
    ChunkList_iterator<ValueType> ChunkList_iterator<ValueType>::operator+(const difference_type &n) const {
//        ChunkList_iterator temp(*this);
//        temp.pointer += n;
//        return temp;
    }

    // Реализация оператора присваивания сложения с числом
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator+=(const difference_type &n) {
        return *this;
    }

    // Реализация оператора вычитания из числа
    template<typename ValueType>
    ChunkList_iterator<ValueType> ChunkList_iterator<ValueType>::operator-(const difference_type &n) const {
//        ChunkList_iterator temp(*this);
//        temp.pointer -= n;
//        return temp;
    }

    // Реализация оператора присваивания вычитания из числа
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator-=(const difference_type &n) {
        return *this;
    }

    // Реализация оператора вычитания двух итераторов
    template<typename ValueType>
    typename ChunkList_iterator<ValueType>::difference_type
    ChunkList_iterator<ValueType>::operator-(const ChunkList_iterator &other) const {
        return *this;
    }

    // Реализация оператора индексации
    template<typename ValueType>
    typename ChunkList_iterator<ValueType>::reference
    ChunkList_iterator<ValueType>::operator[](const difference_type &n) {
        return *(*this + n);
    }

    // Реализация конструктора по умолчанию
    template<typename ValueType>
    ChunkList_const_iterator<ValueType>::ChunkList_const_iterator() noexcept = default;

    // Реализация конструктора копирования
    template<typename ValueType>
    ChunkList_const_iterator<ValueType>::ChunkList_const_iterator(const ChunkList_const_iterator &other) noexcept {
    }

    // Реализация конструктора от обычного итератора
    template<typename ValueType>
    ChunkList_const_iterator<ValueType>::ChunkList_const_iterator(const ChunkList_iterator<ValueType> &) noexcept {}

    // Реализация оператора присваивания
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> &
    ChunkList_const_iterator<ValueType>::operator=(const ChunkList_const_iterator &) {
        return *this;
    }

// Реализация оператора присваивания от обычного итератора
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> &
    ChunkList_const_iterator<ValueType>::operator=(const ChunkList_iterator<ValueType> &) {
        return *this;
    }

// Реализация деструктора
    template<typename ValueType>
    ChunkList_const_iterator<ValueType>::~ChunkList_const_iterator() = default;

// Реализация функции swap
    template<typename ValueType>
    void swap(ChunkList_const_iterator<ValueType> &lhs, ChunkList_const_iterator<ValueType> &rhs) {

    }

// Реализация оператора разыменования *
    template<typename ValueType>
    typename ChunkList_const_iterator<ValueType>::reference ChunkList_const_iterator<ValueType>::operator*() const {

    }

    // Реализация оператора ->
    template<typename ValueType>
    typename ChunkList_const_iterator<ValueType>::pointer ChunkList_const_iterator<ValueType>::operator->() const {

    }

    // Реализация оператора префиксного инкремента
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> &ChunkList_const_iterator<ValueType>::operator++() {
        return *this;
    }

    // Реализация оператора постфиксного инкремента
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> ChunkList_const_iterator<ValueType>::operator++(int) {
        ChunkList_const_iterator temp(*this);
        ++(*this);
        return temp;
    }

    // Реализация оператора префиксного декремента
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> &ChunkList_const_iterator<ValueType>::operator--() {
        return *this;
    }

    // Реализация оператора постфиксного декремента
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> ChunkList_const_iterator<ValueType>::operator--(int) {
        ChunkList_const_iterator temp(*this);
        --(*this);
        return temp;
    }

    // Реализация оператора сложения с числом
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> ChunkList_const_iterator<ValueType>::operator+(const difference_type &) const {
        return *this;
    }

    // Реализация оператора присваивания сложения с числом
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> &ChunkList_const_iterator<ValueType>::operator+=(const difference_type &) {
        return *this;
    }

    // Реализация оператора вычитания из числа
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> ChunkList_const_iterator<ValueType>::operator-(const difference_type &) const {
        return *this;
    }

    // Реализация оператора присваивания вычитания из числа
    template<typename ValueType>
    ChunkList_const_iterator<ValueType> &ChunkList_const_iterator<ValueType>::operator-=(const difference_type &) {
        return *this;
    }

    // Реализация оператора вычитания двух итераторов
    template<typename ValueType>
    typename ChunkList_const_iterator<ValueType>::difference_type
    ChunkList_const_iterator<ValueType>::operator-(const ChunkList_const_iterator &) const {
        return *this;
    }

    // Реализация оператора индексации
    template<typename ValueType>
    typename ChunkList_const_iterator<ValueType>::reference
    ChunkList_const_iterator<ValueType>::operator[](const difference_type &) {
        return *this;
    }

    // Конструктор по умолчанию
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList() = default;

    // Конструктор с аллокатором
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(const Allocator &alloc) {

    }

    // Конструктор с count копиями элементов со значением и аллокатором
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(size_type count, const T &value, const Allocator &alloc) {
        // Реализация логики конструктора с count копиями здесь
    }

    // Конструктор с count экземплярами T, вставленными по умолчанию
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(size_type count, const Allocator &alloc) {
        // Реализация логики конструктора с count экземплярами по умолчанию здесь
    }

    // Конструктор с содержимым диапазона [first, last)
    template<typename T, int N, typename Allocator>
    template<class InputIt>
    ChunkList<T, N, Allocator>::ChunkList(InputIt first, InputIt last, const Allocator &alloc) {
        // Реализация логики конструктора с диапазоном [first, last) здесь
    }

    // Конструктор копирования
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(const ChunkList &other) {
        // Реализация логики конструктора копирования здесь
    }

    // Конструктор копирования с аллокатором
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(const ChunkList &other, const Allocator &alloc) {
        // Реализация логики конструктора копирования с аллокатором здесь
    }

    // Конструктор перемещения
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(ChunkList &&other) {

    }

    // Расширенный конструктор перемещения с аллокатором
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(ChunkList &&other, const Allocator &alloc) {
        // Реализация логики расширенного конструктора перемещения с аллокатором здесь
    }

    // Конструктор с содержимым инициализирующего списка init
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(std::initializer_list<T> init, const Allocator &alloc) {
        // Реализация логики конструктора с инициализирующим списком здесь
    }

    // Деструктор
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::~ChunkList() {
        // Реализация логики деструктора здесь
    }

    // Оператор присваивания копирования
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator> &ChunkList<T, N, Allocator>::operator=(const ChunkList &other) {
        // Реализация логики оператора присваивания копирования здесь
        return *this;
    }

    // Оператор присваивания перемещения
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator> &ChunkList<T, N, Allocator>::operator=(ChunkList &&other) {
        return other;
    }

// Оператор присваивания инициализирующего списка
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator> &ChunkList<T, N, Allocator>::operator=(std::initializer_list<T> ilist) {
        // Реализация логики оператора присваивания инициализирующего списка здесь
        return *this;
    }

// Функция замены содержимого указанным количеством копий значения
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::assign(size_type count, const T &value) {
        // Реализация логики функции assign с указанным количеством копий значения здесь
    }

// Функция замены содержимого копиями элементов из диапазона [first, last)
    template<typename T, int N, typename Allocator>
    template<class InputIt>
    void ChunkList<T, N, Allocator>::assign(InputIt first, InputIt last) {
        // Реализация логики функции assign с копиями элементов из диапазона [first, last) здесь
    }

// Функция замены содержимого элементами из инициализирующего списка
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::assign(std::initializer_list<T> ilist) {
        // Реализация логики функции assign с элементами из инициализирующего списка здесь
    }

// Возвращает аллокатор, связанный с контейнером
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::allocator_type ChunkList<T, N, Allocator>::get_allocator() const noexcept {
        // Реализация логики функции get_allocator здесь
        return allocator_type(); // Заглушка, замените на фактическую логику
    }

// Возвращает ссылку на элемент по указанному местоположению с проверкой границ
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::reference ChunkList<T, N, Allocator>::at(size_type pos) {
        // Реализация логики функции at с проверкой границ здесь
        // Если pos находится в пределах диапазона, возвращаем элемент
        // В противном случае выбрасываем исключение std::out_of_range
    }

// Возвращает константную ссылку на элемент по указанному местоположению с проверкой границ
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_reference ChunkList<T, N, Allocator>::at(size_type pos) const {
        // Реализация логики функции at с проверкой границ для константного случая здесь
    }

// Возвращает ссылку на элемент по указанному местоположению без проверки границ
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::reference ChunkList<T, N, Allocator>::operator[](size_type pos) {
        // Реализация логики функции оператора [] без проверки границ здесь
    }

// Возвращает константную ссылку на элемент по указанному местоположению без проверки границ
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_reference ChunkList<T, N, Allocator>::operator[](size_type pos) const {
        // Реализация логики функции оператора [] без проверки границ для константного случая здесь
    }

// Возвращает ссылку на первый элемент в контейнере
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::reference ChunkList<T, N, Allocator>::front() {
        // Реализация логики функции front здесь
    }

// Возвращает константную ссылку на первый элемент в контейнере
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_reference ChunkList<T, N, Allocator>::front() const {
        // Реализация логики функции front для константного случая здесь
    }

// Возвращает ссылку на последний элемент в контейнере
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::reference ChunkList<T, N, Allocator>::back() {
//        // Проверка на пустоту контейнера
//        if (empty()) {
//            throw std::out_of_range("ChunkList::back(): container is empty");
//        }
//
//        // Возвращаем ссылку на последний элемент
//        return tail_->data[tail_->size - 1];
    }

// Возвращает константную ссылку на последний элемент в контейнере
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_reference ChunkList<T, N, Allocator>::back() const {
//        // Проверка на пустоту контейнера
//        if (empty()) {
//            throw std::out_of_range("ChunkList::back() const: container is empty");
//        }
//
//        // Возвращаем const ссылку на последний элемент
//        return tail_->data[tail_->size - 1];
    }

    // Возвращает итератор, адресующий первый элемент в списке.
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator ChunkList<T, N, Allocator>::begin() noexcept {
        // Реализация логики функции begin здесь
    }

    // Возвращает константный итератор на первый элемент ChunkList
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_iterator ChunkList<T, N, Allocator>::begin() const noexcept {
        // Реализация логики функции begin для константного случая здесь
    }

    // Возвращает константный итератор на первый элемент ChunkList (аналогично begin())
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_iterator ChunkList<T, N, Allocator>::cbegin() const noexcept {
        // Реализация логики функции cbegin здесь
    }

    // Возвращает итератор на элемент, следующий за последним элементом ChunkList
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator ChunkList<T, N, Allocator>::end() noexcept {
        // Реализация логики функции end здесь
    }

    // Возвращает константный итератор на элемент, следующий за последним элементом ChunkList
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_iterator ChunkList<T, N, Allocator>::end() const noexcept {
        // Реализация логики функции end для константного случая здесь
    }

    // Возвращает константный итератор на элемент, следующий за последним элементом ChunkList (аналогично end())
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_iterator ChunkList<T, N, Allocator>::cend() const noexcept {
        // Реализация логики функции cend здесь
    }

    // Проверяет, пуст ли контейнер
    template<typename T, int N, typename Allocator>
    bool ChunkList<T, N, Allocator>::empty() const noexcept {
        // Реализация логики функции empty здесь
    }

    // Возвращает количество элементов в контейнере
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::size_type ChunkList<T, N, Allocator>::size() const noexcept {
        // Реализация логики функции size здесь
    }

    // Возвращает максимальное количество элементов, которые контейнер может содержать
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::size_type ChunkList<T, N, Allocator>::max_size() const noexcept {
        // Реализация логики функции max_size здесь
    }

    // Запрашивает уменьшение неиспользуемой емкости
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::shrink_to_fit() {
        // Реализация логики функции shrink_to_fit здесь
    }

    // Очищает контейнер, удаляя все элементы
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::clear() noexcept {
        // Реализация логики функции clear здесь
    }

    // Вставляет элемент перед указанным положением pos
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator
    ChunkList<T, N, Allocator>::insert(const_iterator pos, const T &value) {
        // Реализация логики функции insert с константным значением здесь
    }

// Вставляет элемент перед указанным положением pos
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator ChunkList<T, N, Allocator>::insert(const_iterator pos, T &&value) {
        // Реализация логики функции insert со значением, перемещаемым с помощью std::move, здесь
    }

// Вставляет count копий значения перед указанным положением pos
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator
    ChunkList<T, N, Allocator>::insert(const_iterator pos, size_type count, const T &value) {
        // Реализация логики функции insert с count копиями значения здесь
    }

// Вставляет элементы из диапазона [first, last) перед указанным положением pos
    template<typename T, int N, typename Allocator>
    template<class InputIt>
    typename ChunkList<T, N, Allocator>::iterator
    ChunkList<T, N, Allocator>::insert(const_iterator pos, InputIt first, InputIt last) {
        // Реализация логики функции insert с элементами из диапазона [first, last) здесь
    }

// Вставляет элементы из инициализирующего списка перед указанным положением pos
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator
    ChunkList<T, N, Allocator>::insert(const_iterator pos, std::initializer_list<T> ilist) {
        // Реализация логики функции insert с элементами из инициализирующего списка здесь
    }

// Вставляет новый элемент непосредственно перед указанным положением pos
    template<typename T, int N, typename Allocator>
    template<class... Args>
    typename ChunkList<T, N, Allocator>::iterator
    ChunkList<T, N, Allocator>::emplace(const_iterator pos, Args &&... args) {
        // Реализация логики функции emplace здесь
    }

// Удаляет элемент в позиции pos
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator ChunkList<T, N, Allocator>::erase(const_iterator pos) {
        // Реализация логики функции erase здесь
    }

// Удаляет элементы в диапазоне [first, last)
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::iterator
    ChunkList<T, N, Allocator>::erase(const_iterator first, const_iterator last) {
        // Реализация логики функции erase для диапазона [first, last) здесь
    }

// Добавляет элемент в конец контейнера
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::push_back(const T &value) {
        // Реализация логики функции push_back с константным значением здесь
    }

// Добавляет элемент в конец контейнера с использованием std::move
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::push_back(T &&value) {
        // Реализация логики функции push_back со значением, перемещаемым с помощью std::move, здесь
    }

// Вставляет новый элемент в конец контейнера
    template<typename T, int N, typename Allocator>
    template<class... Args>
    typename ChunkList<T, N, Allocator>::reference ChunkList<T, N, Allocator>::emplace_back(Args &&... args) {
        // Реализация логики функции emplace_back здесь
    }

// Удаляет последний элемент из контейнера
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::pop_back() {
        // Реализация логики функции pop_back здесь
    }

// Добавляет элемент в начало контейнера
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::push_front(const T &value) {
        // Реализация логики функции push_front с константным значением здесь
    }

// Добавляет элемент в начало контейнера с использованием std::move
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::push_front(T &&value) {
        // Реализация логики функции push_front со значением, перемещаемым с помощью std::move, здесь
    }

// Вставляет новый элемент в начало контейнера
    template<typename T, int N, typename Allocator>
    template<class... Args>
    typename ChunkList<T, N, Allocator>::reference ChunkList<T, N, Allocator>::emplace_front(Args &&... args) {
        // Реализация логики функции emplace_front здесь
    }

// Удаляет первый элемент из контейнера
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::pop_front() {
        // Реализация логики функции pop_front здесь
    }

// Изменяет размер контейнера, чтобы содержать count элементов
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::resize(size_type count) {
        // Реализация логики функции resize здесь
    }

// Изменяет размер контейнера, чтобы содержать count элементов и инициализирует новые элементы значением value
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::resize(size_type count, const value_type &value) {
        // Реализация логики функции resize с инициализацией значением value здесь
    }

// Обменивает содержимое контейнера с содержимым другого контейнера
    template<typename T, int N, typename Allocator>
    void ChunkList<T, N, Allocator>::swap(ChunkList &other) {
        // Реализация логики функции swap здесь
    }


// Оператор сравнения ==
    template<class U, class Alloc>
    bool operator==(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return lhs == rhs;
    }

// Оператор сравнения !=
    template<class U, class Alloc>
    bool operator!=(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return !(lhs == rhs);
    }

// Оператор сравнения >
    template<class U, class Alloc>
    bool operator>(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return lhs > rhs;
    }

// Оператор сравнения <
    template<class U, class Alloc>
    bool operator<(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return lhs < rhs;
    }

// Оператор сравнения >=
    template<class U, class Alloc>
    bool operator>=(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return lhs >= rhs;
    }

// Оператор сравнения <=
    template<class U, class Alloc>
    bool operator<=(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return lhs <= rhs;
    }

// Оператор сравнения <=>
    template<class U, class Alloc>
    bool operator<=>(const ChunkList<U, 0, Alloc> &lhs, const ChunkList<U, 0, Alloc> &rhs) {
        return lhs <=> rhs;
    }

// Функция обмена содержимым двух контейнеров
    template<class T, class Alloc>
    void swap(ChunkList<T, 0, Alloc> &lhs, ChunkList<T, 0, Alloc> &rhs) {
        // Реализация логики функции swap здесь
    }

// Функция удаления всех элементов, равных заданному значению, из контейнера
    template<class T, class Alloc, class U>
    typename ChunkList<T, 0, Alloc>::size_type erase(ChunkList<T, 0, Alloc> &c, const U &value) {
        // Реализация логики функции erase здесь
    }

// Функция удаления всех элементов, удовлетворяющих предикату, из контейнера
    template<class T, class Alloc, class Pred>
    typename ChunkList<T, 0, Alloc>::size_type erase_if(ChunkList<T, 0, Alloc> &c, Pred pred) {
        // Реализация логики функции erase_if здесь
    }
}