# 👋 Hello Prashun Linux Kernel Module

Welcome to the **Hello Prashun** Linux kernel module!  
This is a beginner-friendly, kernel module project that prints messages to the kernel log when loaded and unloaded.

---

## 🤔 What is this?

- A simple Linux kernel module written in C. 
- When loaded: **prints "Hello, Prashun!"** to the kernel log.
- When unloaded: **prints "Goodbye, Prashun!"** to the kernel log.
- Lets you interact with the kernel via loading and unloading the module.

---

## 🛠 Prerequisites

Before you begin, make sure you have:

- A Linux system (Ubuntu recommended)
- Kernel headers installed (`linux-headers-$(uname -r)`)
- GCC compiler & Make (`build-essential`)

---

## 🚀 Step-by-Step Interactive Setup

### 1️⃣ Install Dependencies

Open a terminal and run:

```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
```

---

### 2️⃣ Clone the Repository

```bash
git clone https://github.com/prashun07/hello_prashun_linux_module.git
cd hello_prashun_linux_module
```

---

### 3️⃣ Create the Makefile

Create a file named `Makefile` in this directory with the following content:

```makefile
obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

> 📝 **Tip:** If the file already exists, just review its content!

---

### 4️⃣ Build the Module

```bash
make
```

This creates the `hello.ko` kernel module file.

---

### 5️⃣ Load the Module (Interact with Kernel!)

```bash
sudo insmod hello.ko
```

---

### 6️⃣ See the Interactive Output

Check the kernel log:

```bash
dmesg | tail
```

You should see:

```
Hello, Prashun!
```

---

### 7️⃣ Unload the Module (Another Interaction!)

```bash
sudo rmmod hello
```

---

### 8️⃣ See the Goodbye Message

Check the kernel log again:

```bash
dmesg | tail
```

You should see:

```
Goodbye, Prashun!
```

---

### 9️⃣ Clean Up (Optional)

```bash
make clean
```

---

## 🧑‍💻 How Does It Work?

- `hello.c` contains two main functions:
    - `hello_init`: runs when you load the module, prints "Hello, Prashun!"
    - `hello_exit`: runs when you unload the module, prints "Goodbye, Prashun!"
- **Interactive:** You control when the messages appear by loading/unloading the module!

---

## ⚠️ Notes

- You need **root privileges** (use `sudo`) to insert/remove modules.
- Use `dmesg` to view kernel messages.
- For safety, only experiment on test/dev systems.

---

## 📄 License & Author

- **License:** GPL
- **Author:** Prashun

---

## 🏁 Ready to say Hello to Prashun from your kernel?  
**Try loading and unloading the module, and watch your interactive messages appear!**
