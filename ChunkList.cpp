#include "ChunkList.h"


namespace fefu_laboratory_two {

    // Реализация конструктора по умолчанию
    template<typename T>
    Allocator<T>::Allocator() noexcept = default;

    // Реализация конструктора копирования
    template<typename T>
    Allocator<T>::Allocator(const Allocator &other) noexcept {
        this->value_type = other->value_type;
        this->size_type = other->size_type;
        this->difference_type = other->difference_type;
        this->pointer = other->pointer;
        this->const_pointer = other->const_pointer;
        this->reference = other->reference;
        this->const_reference = other->const_reference;
    }

    // Реализация конструктора копирования от другого типа
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
        this->iterator_category = other->iterator_category;
        this->value_type = other->value_type;
        this->difference_type = other->difference_type;
        this->pointer = other->pointer;
        this->reference = other->reference;
    }

    // Реализация оператора присваивания
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator=(const ChunkList_iterator &other) {
        if (this != &other) {
            this->iterator_category = other->iterator_category;
            this->value_type = other->value_type;
            this->difference_type = other->difference_type;
            this->pointer = other->pointer;
            this->reference = other->reference;
        }
        return *this;
    }

    // Реализация деструктора
    template<typename ValueType>
    ChunkList_iterator<ValueType>::~ChunkList_iterator() = default;

    // Реализация функции swap
    template<typename ValueType>
    void swap(ChunkList_iterator<ValueType> &lhs, ChunkList_iterator<ValueType> &rhs) {
        using std::swap;
        swap(lhs.iterator_category, rhs.iterator_category);
        swap(lhs.value_type, rhs.value_type);
        swap(lhs.difference_type, rhs.difference_type);
        swap(lhs.pointer, rhs.pointer);
        swap(lhs.reference, rhs.reference);
    }

    // Реализация оператора ==
    template<typename ValueType>
    bool operator==(const ChunkList_iterator<ValueType> &lhs,
                    const ChunkList_iterator<ValueType> &rhs) {
        return lhs.pointer == rhs.pointer;
    }

    // Реализация оператора !=
    template<typename ValueType>
    bool operator!=(const ChunkList_iterator<ValueType> &lhs,
                    const ChunkList_iterator<ValueType> &rhs) {
        return !(lhs == rhs);
    }

    // Реализация оператора разыменования *
    template<typename ValueType>
    typename ChunkList_iterator<ValueType>::reference ChunkList_iterator<ValueType>::operator*() const {
        return *this;
    }

    // Реализация оператора ->
    template<typename ValueType>
    typename ChunkList_iterator<ValueType>::pointer ChunkList_iterator<ValueType>::operator->() const {
        return *this;
    }

    // Реализация оператора префиксного инкремента
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
        ChunkList_iterator temp(*this);
        temp.pointer += n;
        return temp;
    }

// Реализация оператора присваивания сложения с числом
    template<typename ValueType>
    ChunkList_iterator<ValueType> &ChunkList_iterator<ValueType>::operator+=(const difference_type &n) {
        return *this;
    }

// Реализация оператора вычитания из числа
    template<typename ValueType>
    ChunkList_iterator<ValueType> ChunkList_iterator<ValueType>::operator-(const difference_type &n) const {
        ChunkList_iterator temp(*this);
        temp.pointer -= n;
        return temp;
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

// Реализация оператора <
    template<typename ValueType>
    bool operator<(const ChunkList_iterator<ValueType> &lhs,
                   const ChunkList_iterator<ValueType> &rhs) {
        return lhs.pointer < rhs.pointer;
    }

// Реализация оператора <=
    template<typename ValueType>
    bool operator<=(const ChunkList_iterator<ValueType> &lhs,
                    const ChunkList_iterator<ValueType> &rhs) {
        return !(rhs < lhs);
    }

// Реализация оператора >
    template<typename ValueType>
    bool operator>(const ChunkList_iterator<ValueType> &lhs,
                   const ChunkList_iterator<ValueType> &rhs) {
        return rhs < lhs;
    }

// Реализация оператора >=
    template<typename ValueType>
    bool operator>=(const ChunkList_iterator<ValueType> &lhs,
                    const ChunkList_iterator<ValueType> &rhs) {
        return !(lhs < rhs);
    }

// Реализация оператора <=>
    template<typename ValueType>
    std::strong_ordering operator<=>(const ChunkList_iterator<ValueType> &lhs,
                                     const ChunkList_iterator<ValueType> &rhs) {
        return lhs.pointer <=> rhs.pointer;
    }


    // Реализация конструктора по умолчанию
    template<typename ValueType>
    ChunkList_const_iterator<ValueType>::ChunkList_const_iterator() noexcept = default;

    // Реализация конструктора копирования
    template<typename ValueType>
    ChunkList_const_iterator<ValueType>::ChunkList_const_iterator(const ChunkList_const_iterator &other) noexcept {
        this->iterator_category = other.std::random_access_iterator_tag;
        this->value_type = other.value_type;
        this->difference_type = other.difference_type;
        this->pointer = other.pointer;
        this->reference = other.reference;
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

    // Реализация оператора ==
    template<typename ValueType>
    bool operator==(const ChunkList_const_iterator<ValueType> &lhs,
                    const ChunkList_const_iterator<ValueType> &rhs) {
        return lhs == rhs;
    }

    // Реализация оператора !=
    template<typename ValueType>
    bool operator!=(const ChunkList_const_iterator<ValueType> &lhs,
                    const ChunkList_const_iterator<ValueType> &rhs) {
        return !(lhs == rhs);
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

    // Реализация оператора <
    template<typename ValueType>
    bool operator<(const ChunkList_const_iterator<ValueType> &lhs,
                   const ChunkList_const_iterator<ValueType> &rhs) {
        return lhs < rhs;
    }

    // Реализация оператора <=
    template<typename ValueType>
    bool operator<=(const ChunkList_const_iterator<ValueType> &lhs,
                    const ChunkList_const_iterator<ValueType> &rhs) {
        return !(rhs < lhs);
    }

    // Реализация оператора >
    template<typename ValueType>
    bool operator>(const ChunkList_const_iterator<ValueType> &lhs,
                   const ChunkList_const_iterator<ValueType> &rhs) {
        return rhs < lhs;
    }

    // Реализация оператора >=
    template<typename ValueType>
    bool operator>=(const ChunkList_const_iterator<ValueType> &lhs,
                    const ChunkList_const_iterator<ValueType> &rhs) {
        return !(lhs < rhs);
    }

    // Реализация оператора <=>
    template<typename ValueType>
    std::strong_ordering operator<=>(const ChunkList_const_iterator<ValueType> &lhs,
                                     const ChunkList_const_iterator<ValueType> &rhs) {
        return lhs <=> rhs;
    }

    // Конструктор по умолчанию
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList() = default;

    // Конструктор с аллокатором
    template<typename T, int N, typename Allocator>
    ChunkList<T, N, Allocator>::ChunkList(const Allocator &alloc) {
//        this->value_type = T;
//        this->allocator_type = Allocator;
//        this->size_type = std::size_t;
//        this->difference_type = std::ptrdiff_t;
//        this->reference = value_type &;
//        this->const_reference = const value_type &;
//        this->pointer = typename std::allocator_traits<Allocator>::pointer;
//        this->const_pointer = typename std::allocator_traits<Allocator>::const_pointer;
//        this->iterator = ChunkList_iterator<value_type>;
//        this->const_iterator = ChunkList_const_iterator<value_type>;
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
    ChunkList<T, N, Allocator>::ChunkList(ChunkList &&other) noexcept {
        // Реализация логики конструктора перемещения здесь
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
    ChunkList<T, N, Allocator> &ChunkList<T, N, Allocator>::operator=(ChunkList &&other) noexcept {
        // Реализация логики оператора присваивания перемещения здесь
        return *this;
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
        // Проверка на пустоту контейнера
        if (empty()) {
            throw std::out_of_range("ChunkList::back(): container is empty");
        }

        // Возвращаем ссылку на последний элемент
        return tail_->data[tail_->size - 1];
    }

    // Возвращает константную ссылку на последний элемент в контейнере
    template<typename T, int N, typename Allocator>
    typename ChunkList<T, N, Allocator>::const_reference ChunkList<T, N, Allocator>::back() const {
        // Проверка на пустоту контейнера
        if (empty()) {
            throw std::out_of_range("ChunkList::back() const: container is empty");
        }

        // Возвращаем const ссылку на последний элемент
        return tail_->data[tail_->size - 1];
    }

    // Возвращает итератор на первый элемент ChunkList
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
    bool operator==(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return lhs == rhs;
    }

    // Оператор сравнения !=
    template<class U, class Alloc>
    bool operator!=(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return !(lhs == rhs);
    }

    // Оператор сравнения >
    template<class U, class Alloc>
    bool operator>(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return lhs > rhs;
    }

    // Оператор сравнения <
    template<class U, class Alloc>
    bool operator<(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return lhs < rhs;
    }

    // Оператор сравнения >=
    template<class U, class Alloc>
    bool operator>=(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return lhs >= rhs;
    }

    // Оператор сравнения <=
    template<class U, class Alloc>
    bool operator<=(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return lhs <= rhs;
    }

    // Оператор сравнения <=>
    template<class U, class Alloc>
    bool operator<=>(const ChunkList<U, Alloc> &lhs, const ChunkList<U, Alloc> &rhs) {
        return lhs <=> rhs;
    }

    // Функция обмена содержимым двух контейнеров
    template<class T, class Alloc>
    void swap(ChunkList<T, Alloc> &lhs, ChunkList<T, Alloc> &rhs) {
        // Реализация логики функции swap здесь
    }

    // Функция удаления всех элементов, равных заданному значению, из контейнера
    template<class T, class Alloc, class U>
    typename ChunkList<T, Alloc>::size_type erase(ChunkList<T, Alloc> &c, const U &value) {
        // Реализация логики функции erase здесь
    }

    // Функция удаления всех элементов, удовлетворяющих предикату, из контейнера
    template<class T, class Alloc, class Pred>
    typename ChunkList<T, Alloc>::size_type erase_if(ChunkList<T, Alloc> &c, Pred pred) {
        // Реализация логики функции erase_if здесь
    }
}