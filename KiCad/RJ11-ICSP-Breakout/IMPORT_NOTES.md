# First-pass KiCad import: RJ11-ICSP-Breakout

- **Source board:** `HBridge84/EagleCad/RJ11-ICSP-Breakout.brd`
- **Source schematic:** `HBridge84/EagleCad/RJ11-ICSP-Breakout.sch`
- **PCB import:** OK (kicad-cli pcb import)
- **Schematic import:** not automated — use KiCad GUI: File → Import Non-KiCad Project → EAGLE Project
- **Date:** 2026-07-19
- **KiCad:** 10.0.4 (`kicad-cli`)

Automated pipeline converts **boards** via `kicad-cli pcb import --format eagle`.
KiCad 10.0.4 has no headless Eagle **schematic** import (`kicad-cli sch` has no `import`;
no Python `SCH_IO_MGR` module shipped). Open the Eagle `.sch` + `.brd` pair in the GUI
importer when you need a linked schematic, or re-import into this folder.

Validate with DRC/ERC before fab. Do not treat this tree as fab-ready.
