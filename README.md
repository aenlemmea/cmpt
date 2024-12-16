```
Support_String::x86_64::GNU/Linux::Unix Makefiles
```

## cmpt (cry tool)

Pronounced: _compete_

Tool to help with competitive programming. Use [Competitive Companion](https://github.com/jmerle/competitive-companion) as an extension for fetching. Mainly for codeforces.

Note: This tool is written for my personal use. Major refactor incoming as this is my first cpp project.

```
  cry >COMMAND<

    A tool to grab metadata from codeforces and manage them locally.

  >COMMAND<:

      Available Commands:
        fo                                Fetch a single problem.
        fc                                Fetch an entire contest. Note: Not for
                                          single problem contests
        fosho                             Inspect the single fetched problem
                                          data. Note: Not json
        config                            Show the default config
      -h, --help                        Display this help menu

    Planned support: dmoj.

```


### USAGE:

1. `cry fo` 

Fetches one problem. Equivalent to `cry --fetch-one`. [Done]

-----

2. `cry fc` 

Fetches entire contest. Equivalent to `cry --fetch-contest` [Done]

-----

3. `crn`

This is a small script to compile if-not run the binary. Must be called from where `sol.cpp` is generated.

If `runfile` is not found, attempts to compile and create `runfile` (`g++ sol.cpp $default_flags -o runfile`) and run it. If no source file found, reports error. The `$default_flags` can be customised with cry tool (See #4 for how).

> [!NOTE] 
> libasan on linux is a prerequisite for using the default flags. It is required by -fsanitize-address. If you don't want to install it. Just set custom flags via cry.

[Done]

-----

4. `cry config <--template> <--template-alias>|<--compile-flags> <--flag-preset-name>|`

Only running `cry config` shows you what the current config is. [Done]

Set the template file and a alias for it or the compiler flags. 

The base minimul compile-flag (`default_flags`) is set to `-Wall -Wextra -O2 -std=c++20 -Wconversion -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address`. Currently `g++` support is baked in, `clang++` support is due.

-----

5. `cry ape <problem-id>`

[Low Priority] Equivalent to `cry --apetize <problem-id>` to dump the problem to any local LLM model and get a much cleaner reading statement. 


### BUILDING

1. CMake will auto populate the deps and recursively hydrate the submodules. (`Crow` framework for the http server).
2. You will manually need to install the `asio-dev` or `asio-devel` library for their headers (needed by crow).
3. Rest create a `build` directory, enter it as: `mkdir -p build && cd build`
4. Run `cmake .. -G "Unix Makefiles"`. or, instead of step 3 and 4: you can run `./build.sh` and it will do everything for you.
5. Run `./build.sh clean` to get a clean slate.

### DIRECTORY STYLE:

For `cry fo`. `cry fc` has the same style but instead of just A2023, we have all subsequent problems B,C,D,.. saved in the 2023 directory. This style allows all problems under a contest to be saved in the same file.

```
2023/
└── A2023
    ├── sol.cpp
    ├── test.in
    └── test.out
```
#### TODO

- [ ] Support dmoj. >High Priority<
- [ ] Support template placement strategies (viz. OVERWRITE or ADD_DUP)
- [ ] Clang++ support for compilation flags
- [ ] Custom directory structre or Alternate directory structure.
- [ ] (Multithreading) Experiment with placing files first in a temp directory then mv after data is fetched. 
- [ ] Color support.
- [ ] Integrate fzf for template pickers.

#### Why `cry`?

Well, the plan was to use `cmp`, but `cmp` is already used as a tool in GNU/Linux environment, hence had to settle for `cry`. Feel free to alias.

#### Rationale

The motivation behind this is due to the lack of a proper and lightweight tool. The closest thing is probably [cf-tool](https://github.com/xalanq/cf-tool) which is really great and awesome (and written by people who actually know what they are doing) but it is not maintained as of the time of writing this, and more importantly aims to be a complete suite of tools, and sadly written in golang. 

`cmpt` does NOT aim to be a complete suite. It is made to be light, fast and barebones if possible. There is no testing, submitting or tracking facilities builtin. The user is expected to do those things themselves.
