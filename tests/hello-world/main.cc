#include <cstdlib>
#include <iostream>

#include "git.h"

int main() {
    if(git::is_populated()) {
        if(git::any_uncommitted_changes()) {
            std::cerr << "WARN: there were uncommitted changes at build-time." << std::endl;
        }
        std::cout << "commit " << git::commit_sha1() << " (" << git::branch() << ")\n"
                  << "describe " << git::describe() << "\n"
                  << "Author: " << git::author_name() << " <" << git::author_email() << ">\n"
                  << "Date: " << git::commit_date() << "\n\n"
                  << git::commit_subject() << "\n" << git::commit_body() << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        std::cerr << "WARN: failed to get the current git state. Is this a git repo?" << std::endl;
        return EXIT_FAILURE;
    }
}
