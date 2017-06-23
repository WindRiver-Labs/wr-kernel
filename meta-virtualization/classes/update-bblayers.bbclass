#
# Copyright (C) 2017 Wind River Systems, Inc.
#
# Replace wr-kernel/meta-virtualization with the standalone meta-virtualization in
# the build's bblayers.conf. Bitbake will receive an inotify and reparse making this
# change all in one go. Derived from oecore_update_bblayers() in sanity.bbclass.
#

addhandler update_bblayers
update_bblayers[eventmask] = "bb.event.ConfigParsed"

python update_bblayers() {
    bb.note("The meta-virtualization layer has been moved from being part of wr-kernel to a standalone layer.")
    bblayers_fn = bblayers_conf_file(d)
    lines = sanity_conf_read(bblayers_fn)

    layers = e.data.getVar('BBLAYERS', True).split()
    layers = [ os.path.basename(path) for path in layers ]

    # No need to search for wr-kernel/meta-virtualization, if we are running it is in there.
    while True:
        index, meta_virtualization_line = sanity_conf_find_line(r'.*wr-kernel/meta-virtualization[\'"\s\n]', lines)
        if meta_virtualization_line:
            lines[index] = meta_virtualization_line.replace('wr-kernel/meta-virtualization', 'meta-virtualization')
        else:
            break

    with open(bblayers_fn, "w") as f:
        f.write(''.join(lines))

    bb.note("Your conf/bblayers.conf has been automatically updated.")
    return
}
