# GameplayBehaviorMonitor

GameplayBehaviorMonitor is an educational C++ project inspired by anti-cheat systems.  
So far this project monitors system behavior by logging events, enumerating running processes, detecting blacklisted applications, and collecting hardware identifiers for ban use cases.

## Features

- **Structured Logger**
  - Multiple log levels: Info, Warn, Error, Detected
  - Timestamped entries
  - Persistent `.txt` log output
- **Process Enumeration**
  - Lists all running processes with names and process IDs
- **Process Blacklisting**
  - Configurable blacklist (by process name) via .txt file
  - Automatic detection and logging when blacklisted processes are found
- **Hardware Identification (HWID Components)**
  - Machine GUID (Windows Registry)
  - Network interface MAC addresses
  - Designed for hardware-based correlation or ban enforcement

## Planned Features (In no particular order)

- Multithreaded architecture
- Log file size limits with automatic rotation
- Heartbeat system
- In-game screenshot capture
- Anti-DLL injection detection
- Input rate analysis to detect automated behavior
- Reaction time analysis to identify non-human responses
- Memory scanning to detect memory reads and writes

## Example Log Output

```
----- Logger initialized -----
[01/16/26 16:03:35] [INFO] Profile Guid = {7925d812-8f6d-49e0-a119-3b50757ca385}
[01/16/26 16:03:35] [INFO] MAC Address: 0F-0A-75-3A-1C-31
[01/16/26 16:03:35] [INFO] MAC Address: BC-AD-AA-9A-DF-78
[01/16/26 16:03:36] [DETECTED] Blacklisted process detected: cheatengine.exe (PID: 43223)
----- Logger Ended -----
```

## License

This project is provided as-is for educational and personal use.

## Contributing

Contributions, suggestions, and discussions are welcome.
Please open an issue or submit a pull request.

## Acknowledgments

- https://cppreference.com/
- https://www.learncpp.com/
- Microsoft Windows API Documentation



