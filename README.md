General ADC DAC board - app template
====================================

This is a template project that uses the general-purpose ADC / DAC board in use
in the ICL Ultracold Strontium Laboratory. This repository uses PlatformIO to
import the GeneralADCDAC library as a dependency. You should install Visual
Studio Code and the PlatformIO extension.

To use this template, either:

1. Clone this project into a new folder
2. Delete the git history: `rm -rf .git`
3. Reinitialise it as a new project: `git init && git add . && git commit -am "Init"`

Or:

1. Use the "New project" button in the "Genreal ADC DAC board" group on GitLab
2. Select "Create from Template"
3. Select the "General ADC DAC board" template

Then, in either case, set up the "latest_hash.h" versioning by copying the
`hooks` into `.git/hooks`:

```bash
cp hooks/* .git/hooks.
```
