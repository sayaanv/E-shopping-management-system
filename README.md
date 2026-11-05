# E-Shopping Management System

A menu-driven console shopping-cart program that demonstrates basic product selection and cart-total logic.

## Features

- Browse computer accessories, shoes, and mobile phones.
- View fixed product prices in Indian rupees.
- Confirm purchases before adding products to the cart.
- Track item quantities, line totals, and the overall cart total.
- Choose to add more products or remove an item.

## How It Works

Enter a name, choose a product category, select an item, and confirm the purchase. The program displays the cart and calculates the final total.

## Technology

- C-style console programming
- Standard input and output

The source file currently has a `.cpp` extension.

## Scope

This is a console prototype. It does not include a web interface, online payments, live inventory, or a database.

## Known Issues

- The remove-item logic does not accept product ID `0`.
- The program uses `gets()` for name input; this should be replaced with a bounded input method.
