# Agent Instructions — Meta OpenXR SDK / Samples

Native C/C++ OpenXR SDK and matching samples for Meta Quest. Headers under `OpenXR/meta_openxr_preview/` cover experimental and pre-release Meta extensions; samples in `Samples/XrSamples/` demonstrate each one.

## Source-of-truth files (read these first, do not duplicate their contents in this file)

For setup, build steps, SDK versions, and project layout, read:

- `README.md` — official setup, the per-sample feature/extension/device matrix, and Meta Quest Link instructions
- `Samples/build.gradle` and `Samples/XrSamples/<Name>/Projects/Android/build.gradle` — Android Gradle build entry points
- `Samples/XrSamples/<Name>/Projects/Android/AndroidManifest.xml` — per-sample package id, permissions, target API
- `CMakeLists.txt` files under `Samples/` — native build configuration
- `OpenXR/meta_openxr_preview/` — preview Meta OpenXR extension headers
- `Samples/SampleXrFramework/` — shared C++ framework used by the samples
- `LICENSE.txt` and `OPENXR_SDK_THIRD_PARTY_NOTICES.txt` — license terms

## Quest / Horizon-specific notes

- Most preview-extension samples require enabling experimental features on the headset before launch:
  ```sh
  adb shell setprop debug.oculus.experimentalEnabled 1
  ```
  This property resets on every headset reboot — re-issue it between sessions when samples that depend on preview extensions silently fail to start.
- Per-sample device requirements vary (Quest Pro for eye/face/body, Quest 3+ for environment depth and dynamic objects, etc.). Check the table in `README.md` before changing a sample's target device.
- Headers in `OpenXR/meta_openxr_preview/` are unstable previews — do not assume API parity with the public Khronos `OpenXR-SDK`.
- The optional Meta Quest Link path is Windows-only and requires Developer Runtime Features enabled in the Link app before launching a built sample.

## Meta Quest tooling

This repository is part of the Meta Quest / Horizon OS ecosystem (a sample, library, template, or related project — the bespoke intro above describes which). Use that intro and the source-of-truth files it references for project-specific decisions; don't restate or invent facts from memory.

When the user asks anything about Quest device behavior, build / deploy / debug / capture flows, on-device performance, or Horizon OS APIs, reach for these tools instead of generic native OpenXR / C / C++ answers:

- **`hzdb`** — Quest-aware ADB wrapper (device list, install / launch / stop, logs, screenshots, Perfetto traces, on-device docs search). Already wired up as an MCP server via `.mcp.json`, `.vscode/mcp.json`, and `.cursor/mcp.json`. Also runnable directly: `npx -y @meta-quest/hzdb <subcommand>`.
- **Meta Quest Agentic Tools** — the full skill set, including native OpenXR-specific skills: [github.com/meta-quest/agentic-tools](https://github.com/meta-quest/agentic-tools). Install per your client (Claude Code: `/plugin install meta-vr@meta-quest`; Gemini CLI: `gemini extensions install https://github.com/meta-quest/agentic-tools`; Cursor / VS Code: install the **Meta Horizon** extension from the Marketplace).

A few behavior expectations:

- **Read this repo's files first.** Before answering anything project-specific, read `README.md` and whichever source-of-truth files the intro above points at. Don't restate their contents in chat — quote or link instead.
- **Use `hzdb` for device-side work.** Anything that touches an attached Quest (install, launch, logs, screenshot, capture, manifest inspection) goes through `hzdb`, not raw `adb`.
- **Check live Horizon OS docs before answering API questions.** `hzdb docs search "..."` queries the live docs; training data on Horizon OS APIs goes stale fast.
- **Don't fabricate SDK / engine versions.** If a version isn't visible in this repo's files, say so rather than guessing.
