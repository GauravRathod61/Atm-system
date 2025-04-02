# 🏧 ATM Management System 💰  

Welcome to the **ATM Management System**, a powerful C++ program simulating a real-world Automated Teller Machine (ATM). This project allows users to securely **deposit, withdraw, check balances, and view transactions**. It also includes an **admin panel** for monitoring all user accounts.  

---

## ✨ Features  

✅ **User Authentication** – Secure login with masked PIN entry.  
✅ **Account Creation** – Register with a unique account number and PIN.  
✅ **Deposit Money** – Instantly add money to your balance.  
✅ **Withdraw Money** – Withdraw cash with note denomination breakdown.  
✅ **Daily Withdrawal Limit** – Maximum limit of **₹10,000 per day**.  
✅ **Transaction History** – View past deposits and withdrawals.  
✅ **Admin Panel** – View all user accounts and balances.  
✅ **Persistent Data Storage** – Saves user data in `users.txt` for future use.  

---

## 🚀 How It Works  

### Step 1️⃣: Run the Program  
Compile and execute the C++ program. You will see the following menu:  


---

### Step 2️⃣: Register a New Account  
If you are a new user, choose **2. Register**, then enter:  
- **Account Number** (Unique ID)  
- **Full Name**  
- **Set a PIN** (Hidden input for security)  

Your account is now created! 🎉  

---

### Step 3️⃣: Login to Your Account  
Select **1. Login**, enter your **Account Number** and **PIN**. If correct, you'll see:  


🔴 If you enter the wrong details **3 times**, the program **exits automatically** for security.  

---

### Step 4️⃣: Use ATM Services  
Once logged in, you can access the following options:  


#### 🏦 Deposit Money  
- Enter the amount you want to deposit.  
- The amount is added to your balance.  

#### 💸 Withdraw Money  
- Enter the amount to withdraw.  
- Money is dispensed with proper **₹500, ₹200, ₹100 note distribution**.  
- Maximum daily limit: **₹10,000**.  

#### 💰 Check Balance  
- Displays your current balance.  

#### 📜 View Transactions  
- Shows a history of **all deposits and withdrawals**.  

---

### Step 5️⃣: Admin Panel Access  
👨‍💻 **Admin Account:**  
- Login with:  

- View **all user accounts and balances**.  

---

## 🔧 Installation & Compilation  

### 🖥️ Prerequisites  
- A **C++ compiler** (e.g., `g++`)  
- **Windows Users**: Required `<conio.h>` for masked PIN entry  

## conclusion
* Overall, this **ATM system** ensures secure, efficient, and user-friendly transactions, enhancing the banking experience for all users. 
