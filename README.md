# Task Checker

**Technologies:**
- **QtQuick 2.6 (QtCreator 5.14)**
- **QML-based UI**
- **STL C++17**

## Summary

The **Task Checker** project is a QML GUI-based application designed to check the completion of tasks. It provides a multi-page interface where each page contains a set of tasks to be verified. Tasks can range from simple file existence checks to more complex system operations, such as verifying the presence of libraries or performing compatibility checks.

### Features:
- **Multi-Page Support**: The application supports multiple pages, each containing a batch of tasks to be checked.
- **Non-blocking Task Execution**: All tasks on a page are executed concurrently in a non-blocking manner, allowing for an efficient user experience without freezing the interface.
- **Progress Monitoring**: Each page contains its own progress bar that updates dynamically based on task completion. Successful tasks increase the progress, while failed tasks decrease it.
- **Task Descriptions**: Each task is displayed with a description that explains what the task does (e.g., checking for file existence, copying files, etc.).

### Task Structure

Each task consists of two main components:
1. **Checker**: A function that checks a specific condition and returns `true` (success) or `false` (failure).
2. **Operation**: The action that should be performed for the task, such as copying a file or verifying a device connection.

#### Example Task:
- **Checker**: Checks the existence of a static library (`lib.a`) in a specific path.
- **Operation**: Copies the library (`lib.a`) into the specific path if it does not exist.

### Task Execution Flow

1. **Enter a Page**: Upon entering a page, the associated tasks are triggered automatically.
2. **Non-blocking Execution**: Tasks are executed simultaneously, ensuring that the UI remains responsive.
3. **Progress Update**: After each task is completed:
   - If the task is successful (`true`), a tick is shown, and the overall progress of the page increases.
   - If the task fails (`false`), the progress bar decreases.

### Advantages
- Modular and Scalable: The application is designed to handle a growing number of tasks and pages, making it easy to extend for future use cases.
- Non-blocking Execution: Tasks are executed concurrently without blocking the user interface, ensuring the application remains responsive.
- User-Friendly Interface: The QML-based UI is intuitive and provides clear task descriptions and progress feedback, making it easy for users to monitor and interact with tasks.
- Real-Time Progress Monitoring: As tasks complete, the progress bars update in real-time, providing users with immediate feedback on task completion.
- Efficient Backend with C++: The C++17 backend ensures fast and efficient execution of task checks, even for large sets of tasks.

### Tasks
- Tasks in the Task Checker project can be anything that you need to execute and verify within the system.
- These can include simple checks like file existence or more complex system operations such as:
-- Verifying the presence of libraries or executables in certain paths.
-- Pinging devices or servers to check connectivity.
-- Checking compatibility of hardware or software configurations.

Tasks are executed and categorized into pages, allowing users to easily navigate and track the progress of each task.


```
Pages

-------------------------------------------------
                Title 1

[✔] Task description 100
[X] Task description 101
[✔] Task description 102
[X] Task description 103
[✔] Task description 104
[✔] Task description 105
[✔] Task description 106
[X] Task description 107

     |============ 71% ==>           |
-------------------------------------------------
```
