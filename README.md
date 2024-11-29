## cmpt (cry tool)

Tool to help with competitive programming. Use [Competitive Companion](https://github.com/jmerle/competitive-companion) as an extension for fetching.

### USAGE:

1. `cry fo` 

Fetches one problem. Equivalent to `cry --fetch-one`

-----

2. `cry fc` 

Fetches entire contest. Equivalent to `cry --fetch-contest`

-----

3. `cry rn <binary-name>`

Run the binary-name. If binary-name is not found, attempts to compile and run from source file that matches binary-name. If no source file found, reports error

-----

4. `cry rt <binary-name>`

Test the binary name with the prefetched test\_case.in and test\_case.out files. If binary-name is not found, attempt to compile, run and test. Compilation criteria is same as for `cry rn`

-----

5. `cry config <--template>|<--compile-flags>|<--test-req>|<--clean-args>`

Set the template file and a alias for it or the compiler flags or the testing requirements. Set cleaning arguments for what files with stated extensions will be removed by `cry clean`.
Set template placement strategy i.e, OVERWRITE or ADD\_DUPLICATE. Also pick template via aliases that would be placed in the directories.

-----

6. `cry clean <...contest-id>|<problem-id>`

WARNING. Attempts to delete all the binary-name. If ran with contest-id, deletes all binaries found in that directory. Multiple contest-ids can be stated

-----

7. `cry ape <problem-id>`

[Low Priority] Equivalent to `cry --apetize <problem-id>` to dump the problem to any local LLM model and get a much cleaner reading statement. 


### BUILDING

1. CMake will auto populate the deps and recursively hydrate the submodules. (`Crow` framework for the http server).
2. You will manually need to install the `asio-dev` or `asio-devel` library for their headers (needed by crow).
3. Rest create a `build` directory, enter it as: `mkdir -p build && cd build`
4. Run `cmake .. -G "Unix Makefiles"`. or, instead of step 3 and 4: you can run `./build.sh` and it will do everything for you.
5. Run `./build.sh` to get a clean slate.

### DIRECTORY STYLE:

For `cry fo <problem-id>`

```
A2019/
├── sol.cpp
├── test_case.in
└── test_case.out

```
#### Why `cry`?

Well, the plan was to use `cmp`, but `cmp` is already used as a tool in GNU/Linux environment, hence had to settle for `cry`. Feel free to alias.
