#ifndef CMPT_MODELS_PROBLEM_MODEL_ONE_HH
#define CMPT_MODELS_PROBLEM_MODEL_ONE_HH

#include <string>
#include <vector>
#include <cstdint>

// Test case data
struct __test {
    std::string input;
    std::string output;
};


// Batch configuration
struct __batch {
    std::string id;  // UUIDv4
    uint32_t size;        // Size of the batch
};


namespace cmpt {
    struct problem {
        std::string name;               // The full name of the problem
        std::string group;              // Contest name?
        std::string url;                // Contest URL
        std::vector<__test> tests;      // Array of test cases
        std::string testType;           // Type of the tests (single or multiNumber). TODO Figure out what to do about multiNumber
        __batch batch;                  // Batch information
        uint32_t numTestCases;


        // Not using the following options for now.
        // __input inputConfig;         // Input configuration
        // __output outputConfig;       // Output configuration
        // __java_settings languages;   // Java specific settings
        // bool interactive = false;    // Optional: Whether this is an interactive problem
        // int memoryLimit = 0;         // Memory limit in MB
        // int timeLimit = 0;           // Time limit in ms
    };

    // Java-specific configuration
    // struct __java_settings {
    //     std::string mainClass;
    //     std::string taskClass;
    // };

    // Input configuration
    // struct __input {
    //     struct Stdin {};
    //     struct File {
    //         std::string fileName;
    //     };
    //     struct Regex {
    //         std::string pattern;
    //     };
    //
    //     // Supported input types
    //     std::shared_ptr<Stdin> stdin;
    //     std::shared_ptr<File> file;
    //     std::shared_ptr<Regex> regex;
    // };

    // Output configuration
    // struct __output {
    //     struct Stdout {};
    //     struct File {
    //         std::string fileName;
    //     };
    //
    //     // Supported output types
    //     std::shared_ptr<Stdout> stdout;
    //     std::shared_ptr<File> file;
    // };
};



#endif
