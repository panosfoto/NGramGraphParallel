# NGramGraphParallel
A generic implementation of n-gram graphs, designed to be able to handle not only texts (or text strings in general) but any custom data format, without changes to the main structure of the code.\
Also, in the future support for OpenCL will be added to speed up workload-heavy graph operations with parallelization.

## Features
* **Flexibility**: The basic n-gram graph representation (see [George Giannakopoulos](http://users.iit.demokritos.gr/~ggianna/)' [thesis, Chapter 3](http://users.iit.demokritos.gr/~ggianna/thesis.pdf) for additional information) is expanded and defined generic, which results in data-agnostic and reusable code. In detail, the "text" and "n-gram" are replaced by "payload" and "atom"; In other words, an entity and the smallest pieces this entity can be split into. This enables custom represantation of other data types (e.g. DNA), which leads to clearer representation and maybe better performance than the equivalent string one.
* **Scalability**: Through parallelization, workload-heavy graph operations can speed up significantly. Real life scenarios may contain a large amount of data, and parallelizing specific operations (e.g. graph comparisons) can bring execution time for big datasets down to reasonable levels. Parallelization is not implemented yet.

## Dependencies
* [Boost](https://www.boost.org/) : NGramGraphParallel uses [Boost's Graph library](https://www.boost.org/doc/libs/1_68_0/libs/graph/doc/index.html) for its graphs. To be able to run the code, you must have boost installed in your system.
You can download the boost libraries [here](https://www.boost.org/users/download/).
* [OpenCL](https://www.khronos.org/opencl/) : The parallelization of the workload is going to use OpenCL. [Compatible hardware](https://en.wikipedia.org/wiki/OpenCL#Version_support) and their appropriate driver(s) are required. (not implemented yet, so not necessary)

## Version
v0.1 This version is the result of a 3-month internship. Only basic functionalities are implemented.
This version includes:
* The generic n-gram graphs representation. 
* Implementation for both generic and specialized (only for text) graphs.
* Basic graph operations and functionality.
* Support for [DOT](http://www.graphviz.org/doc/info/lang.html) language representation of n-Gram graphs.

## License
NGramGraphParallel is licenced under [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0).
