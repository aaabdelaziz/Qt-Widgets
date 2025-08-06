# Lesson 2 - Connecting Signals to Slots in Qt Widgets

In this lesson, we demonstrate **three different methods** of connecting a `QPushButton`'s `clicked()` signal to a slot in a `QDialog`-based Qt Widgets application. Understanding signals and slots is fundamental in Qt for building interactive GUI applications.

## Methods of Connecting Signals and Slots

There are multiple ways to connect a button to some behavior in Qt. 


+ Manual slot creation and connection using `connect()` function  
+ Auto-connected slot using Qt Designer's naming convention  
+ Inline connection inside constructor using modern signal-slot syntax  (Clean, flexible, and readable)

This Lesson covers:
1. Manual slot method with explicit `connect()`  
2. Auto slot via Qt Creator (`on_<object>_<signal>()`)  
3. Direct connect in constructor using lambda or slot reference  

### Code Highlights

- The slot `Dialog::dostuff()` is created manually and connected using `connect(...)`  
- The slot `Dialog::on_btnEditor_clicked()` is auto-connected by Qt Creator  
- A direct connection using `connect(ui->btnConnect, &QPushButton::clicked, this, &Dialog::dostuff);` is done inside the constructor  

---

## How the Three Methods Work

### 1. Manual Slot Connection

```cpp
void Dialog::dostuff()
{
    qInfo() << "Clicked " << QDateTime::currentDateTime().toString();
    // accept();  // optional: to close the dialog
}
```

### 2. Auto-Connected Slot from Designer

```cpp
void Dialog::on_btnEditor_clicked()
{
    qDebug() << "Extra Stuff !!";
    dostuff();
}
```

This function is auto-called when `btnEditor` is clicked because the slot name follows the pattern: `on_<objectname>_<signal>()`.

### 3. Direct connect using modern signal-slot syntax

Inside the `Dialog` constructor:

```cpp
connect(ui->btnConnect, &QPushButton::clicked, this, &Dialog::dostuff);
```

This connects `btnConnect`'s signal to `dostuff()` without needing the slot to be auto-generated or named specially.

---

## Suggested Reading

Find here good documentation for different Qt frameworks, Tools and API references  https://doc.qt.io/,  
or here for Qt Creator (https://doc.qt.io/qtcreator/creator-quick-tour.html).


More Concepts Coming Soon
--------------------------

Stay tuned for signal overloads, custom signals, and lambda expressions.
