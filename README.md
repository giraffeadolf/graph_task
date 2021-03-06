# Алгоритм по поиску компонент связности графа и выводу их списком вершин в порядке нумерации в матрице смежности
Поиск компонент осуществляется с помощью использования алгоритма поиска в глубину. После первой итерации находится первая компонента связности, затем находится вершина, которая не была посещена во время работы алгоритма, и поиск в глубину осуществляется с этой вершины. Процесс продолжается до тех пор, пока все вершины графа не будут посещены.
## Описание шагов алгоритма
1. Сначала происходит считывание матрицы смежности и аллоцирование памяти для необходимых структур алгоритма
2. Берётся первая непосещённая вершина
3. Заводится цикл, выполняющий блок, пока существуют непосещённые вершины
4. Внутри цикла выполняется DFS, возвращающий массив, в котором на месте с номером вершины, входящей в компоненту связности, стоит единица
   1. В DFS заводится стек, в который помещаются вершины, которые будут посещены, туда заносится начальная вершина, также она помечается как посещённая и заносится в массив компонент связности
   2. Заводится цикл, работающий, пока стек не пустой
   3. В цикле из стека достаётся вершина, затем в стек заносятся все смежные с ней вершины, они помечаются как посещённые и заносятся в массив компонент связности
8. После выполнения DFS компоненты связности печатаются в файл, затем выбирается новая непосещённая вершина
9. Когда все вершины оказываются посещёнными, цикл завершается, после этого происходит очистка памяти
## Тесты
Чтобы проверить программу на одном из четырёх тестах, нужно в седьмой строке ввести соответствующее название файла теста
