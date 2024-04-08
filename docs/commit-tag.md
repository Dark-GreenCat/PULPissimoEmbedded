# **Commit Message Guide**

When committing changes, it's important to use clear and descriptive commit messages. This guide provides a set of tags that you can use in your commit messages to make them more informative and easy to understand.

## **1. How to Use Tags**

Each commit message should start with a tag enclosed in square brackets. The tag should be followed by a space and then your commit message. Here's the general format:

```
[TAG] Your commit message
```

## **2. List of Tags**

Here's a table that lists the tags and their descriptions:

|       | Tag           | Description | Example |
| ---   | ---           | --- | --- |
| 1     | `[INIT]`      | Use this tag when initializing a new repository. | `[INIT] Initialize new embedded project with README and .gitignore` |
| 2     | `[ADD]`       | Use this tag when adding new files or new code to the repository. | `[ADD] Add new UART driver` |
| 3     | `[MODIFY]`    | Use this tag when making changes to existing code in the repository. | `[MODIFY] Refactor UART driver to use DMA` |
| 4     | `[REMOVE]`    | Use this tag when removing files or code from the repository. | `[REMOVE] Delete deprecated SPI driver` |
| 5     | `[DONE]`      | Use this tag when completing a task or a feature. | `[DONE] Complete I2C driver with tests` |
| 6     | `[FIX]`       | Use this tag when making a bug fix. | `[FIX] Fix bug in I2C driver where clock stretching was not handled correctly` |
| 7     | `[REFACTOR]`  | Use this tag when refactoring the code without changing its behavior. | `[REFACTOR] Clean up I2C driver code for readability` |
| 8     | `[STYLE]`     | Use this tag when making style changes (like indentation, formatting, etc.) that do not affect the code's logic or functionality. | `[STYLE] Reformat I2C driver code to follow style guide` |
| 9     | `[TEST]`      | Use this tag when adding or modifying tests. | `[TEST] Add tests for I2C driver` |
| 10     | `[DOCS]`      | Use this tag when adding or updating documentation. | `[DOCS] Add documentation for I2C driver` |
| 11     | `[UPDATE]`    | Use this tag when updating some parts of the code or files. | `[UPDATE] Update I2C driver to support multi-master mode` |
| 12     | `[IMPROVE]`   | Use this tag when improving or optimizing an existing feature. | `[IMPROVE] Optimize I2C driver for lower power consumption` |
| 13     | `[CLEANUP]`   | Use this tag when cleaning up the code or files, such as removing unnecessary comments or unused variables. | `[CLEANUP] Remove unused variables from I2C driver` |
| 14     | `[REVERT]`    | Use this tag when reverting the code back to a previous state. | `[REVERT] Revert I2C driver to previous version due to bugs` |
| 15     | `[MERGE]`     | Use this tag when merging branches. | `[MERGE] Merge I2C driver feature branch into develop` |
| 16     | `[CONFIG]`    | Use this tag when making changes to configuration files. | `[CONFIG] Update config for I2C driver` |
| 17     | `[UI]`        | Use this tag when making changes to the user interface. | `[UI] Update UI for embedded system status display` |
| 18     | `[SECURITY]`  | Use this tag when making changes related to security. | `[SECURITY] Add secure boot to embedded system` |
| 19     | `[PERFORMANCE]`| Use this tag when making changes that improve performance. | `[PERFORMANCE] Improve performance of embedded system boot time` |
| 20     | `[BUILD]`     | Use this tag when making changes related to the build system. | `[BUILD] Update build script for embedded system firmware` |
