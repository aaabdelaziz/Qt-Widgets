# Qt Widgets Lessons Repository 🎓

Welcome! This repository contains a series of Qt Widget examples and lessons designed to teach the fundamentals of Qt Widget (GUI programming) in C++.  

This tutorial code is inspired by the **“Qt Widgets for Beginners with C++”** course by Bryan Cairns, this project follows a practical, topic-based structure you can build using **Qt Creator** or the command line.

---

## 📚 Topics & Lessons Overview

This repo covers the following core Qt Widget topics:

1. **Introduction to QWidget & Basic UI Elements**  
   - QWidget, QPushButton, QCheckBox, QRadioButton, QGroupBox, QFrame, etc.

2. **Layouts**  
   - Absolute positioning, QHBoxLayout, QVBoxLayout, QGridLayout, nested layouts.

3. **Core Widgets & Controls**  
   - QLineEdit, QTextEdit, QComboBox, QListWidget, QSpinBox, etc.

4. **Containers & Navigation Widgets**  
   - QTabWidget, QStackedWidget, QGroupBox, QFrame.

5. **Dialogs & Interaction**  
   - QDialog, modal vs modeless, signals & slots, user input forms.

6. **Main Windows & Menus**  
   - QMainWindow, menu bars, toolbars, status bars.

7. **Advanced Widgets & Containers**  
   - QTreeWidget, QListWidget, QTableWidget, MDI via QMdiArea.

8. **Model‑View Programming (MVC)**  
   - QStringListModel, QFileSystemModel, QStandardItemModel (list, table, tree).

9. **Rich Text & Plain Text Editors**  
   - QTextEdit, file handling, clipboard, formatting, HTML.

10. **Example Applications**  
    - Example projects combining multiple widgets and concepts into complete apps.

---

## 🗂 Repository Structure

    QtLessons/
        ├── Lesson1/
        │ ├── Lesson1.pro
        │ ├── main.cpp
        │ ├── widget1.cpp/.h
        │ ├── widget1.ui
        │ └── README.md
        ├── Lesson2/
        │ └── … same structure for each lesson …
        ├── .gitignore
        └── README.md ← This main overview file


## 🚀 Build & Run Instructions

To build and run these lessons smoothly, it is strongly recommended to install Qt Creator version 6.x or later.
This version includes modern C++ syntax highlighting, a better code navigation experience, and improved integration with the Qt Widgets framework.

## 🧰 Recommended Setup

- Qt Creator ≥ 6.0
- Qt 5.x or Qt 6.x (depending on your system)
- C++ compiler (e.g., GCC, Clang, or MSVC)
- qmake (included with Qt)

## 🔧 Using Qt Creator (Recommended)
1. Launch Qt Creator v6, select the workspace to open for the project.
2. Open the lesson you want to try (e.g. Lesson1)
3. Click Configure Project if needed to adjust the kit and compiler.
4. Click Run (▶️) to build and launch the app.

💡 Qt Creator v6 makes the interface much easier to explore, with modern code editing features and better .ui integration.

## 🖥️ Using Terminal (Alternative with qmake)
    cd Lesson1
    qmake Lesson1.pro
    make
    ./Lesson1