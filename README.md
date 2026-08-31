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
| `l2-task1` | Observe and fix a race condition | [docs/l2-task1.md](docs/l2-task1.md) |

Each tag is a snapshot of `app/` for that task. Build and flash a task with:

    cd app
    west build -b nrf54l15dk/nrf54l15/cpuapp -d build-<tag> .
    west flash -d build-<tag>

Add `-p` when switching boards or after changing `prj.conf`.
