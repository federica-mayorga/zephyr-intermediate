# Zephyr Training Environment

Welcome to the Zephyr RTOS training! This repository includes a ready-to-use
development environment based on Zephyr **4.4.0**, which you can set up in one of
three ways:

---

## Manual Zephyr Setup

Follow the following guide:
- [Getting Started Guide](https://docs.zephyrproject.org/4.4.0/develop/getting_started/index.html#).

Make sure to select appropriate OS and to perform all steps till
[Build the Blinky Sample](https://docs.zephyrproject.org/4.4.0/develop/getting_started/index.html#build-the-blinky-sample).

---

## Course Tasks

| Tag | Task | Notes |
|-----|------|-------|
| `l1-task1` | Ready vs Waiting, `k_yield` vs `k_sleep` | [docs/l1-task1.md](docs/l1-task1.md) |

Build and flash:

    cd app
    west build -b nrf54l15dk/nrf54l15/cpuapp -d build-l1-task1 .
    west flash -d build-l1-task1
