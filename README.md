\# ds-toolkit-cpp



!\[CI](https://github.com/Christykaram/ds-toolkit-cpp/actions/workflows/ci.yml/badge.svg)

!\[C++17](https://img.shields.io/badge/C%2B%2B-17-blue)

!\[License: MIT](https://img.shields.io/badge/License-MIT-green)



A small C++17 library of generic data structures, built from scratch with unit tests and continuous integration.



\## Features



\- `Stack<T>`: LIFO stack backed by a singly linked list

\- `Queue<T>`: FIFO queue backed by a singly linked list with head and tail pointers

\- Header-only, no external dependencies

\- Throws `std::runtime\_error` on invalid operations (for example `pop` on an empty stack)

\- Memory is freed in the destructors, with no leaks

\- Unit tests run automatically with GitHub Actions on every push and pull request



\## Project structure



```

ds-toolkit-cpp/

├── include/

│   ├── Stack.hpp

│   └── Queue.hpp

├── src/

│   └── main.cpp

├── tests/

│   ├── test\_stack.cpp

│   └── test\_queue.cpp

├── .github/workflows/ci.yml

├── .gitignore

├── LICENSE

└── README.md

```



\## Build and run



Requires a C++17 compiler such as g++.



```

g++ -std=c++17 -Wall -Wextra -Iinclude src/main.cpp -o demo

./demo

```



On Windows, use `demo.exe` instead of `./demo`.



\## Run the tests



```

g++ -std=c++17 -Wall -Wextra -Iinclude tests/test\_stack.cpp -o test\_stack

./test\_stack



g++ -std=c++17 -Wall -Wextra -Iinclude tests/test\_queue.cpp -o test\_queue

./test\_queue

```



Each program prints a success message and exits with code 0 when all checks pass.



\## Example usage



```cpp

\#include "Stack.hpp"

\#include "Queue.hpp"



ds::Stack<int> stack;

stack.push(1);

stack.push(2);

stack.top();   // 2

stack.pop();



ds::Queue<int> queue;

queue.enqueue(1);

queue.enqueue(2);

queue.front(); // 1

queue.dequeue();

```



\## What I learned



\- Implementing templates and linked data structures with manual memory management

\- Writing unit tests, including edge cases such as reusing a queue after it empties

\- Working with Git branches, Pull Requests, Issues, and GitHub Actions



\## Possible improvements



\- Copy and move constructors

\- Iterators

\- Additional structures (deque, binary search tree)



\## License



MIT License. See the `LICENSE` file.



Author: Christy Karam

