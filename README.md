# 🔐 Threshold-Based Secret Reconstruction in C++ (Inspired by Shamir's Secret Sharing)

This project demonstrates how to reconstruct a hidden secret from a threshold number of encoded shares using **Lagrange Interpolation**, inspired by **Shamir's Secret Sharing**.

---

## 📘 Overview

This implementation:
- Accepts encoded shares in JSON format.
- Decodes base-N strings into decimal values.
- Uses the first `k` shares to reconstruct the original secret (i.e., the constant term of a polynomial).

---

## 🛠 How It Works

### 🔓 Decode Values
Each share contains a number encoded in a given base (e.g., base-16 or base-36). These are decoded into decimal.

### 🎯 Select Shares
From the full list of shares, the first `k` shares are selected for secret reconstruction.

### 📐 Reconstruct Secret
Uses **Lagrange Interpolation** to compute `f(0)` (the constant term of the polynomial):

\[
f(0) = \sum_{i=0}^{k-1} y_i \cdot \prod_{\substack{j=0 \\ j \ne i}}^{k-1} \frac{-x_j}{x_i - x_j}
\]

---

## 🚀 How to Run

### 🔧 Requirements
- C++ Compiler (e.g., `g++`)
- `nlohmann/json` header file ([json.hpp](https://github.com/nlohmann/json))

### 🧪 Steps

1. Place your input files `testcase1.json` and `testcase2.json` in the project directory.
2. Save the C++ code in a file named `main.cpp`.
3. Compile the code:

💡 Learnings
Core concept behind Shamir's Secret Sharing (reconstruction only)
Practical use of Lagrange Polynomial Interpolation
Handling base-N encoding/decoding in C++
JSON parsing using nlohmann's modern C++ JSON library
