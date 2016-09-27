# This class mangles the SRC_URI to change the network location to the value
# found in URLMAP.  If the params specify the protocol as "file" and there is
# no network location, then the path is checked for validity and SRC_URI is
# only altered if the path does not exist.  The path is stripped to the last
# directory and .git is removed from the last directory name, if present.

python __anonymous () {
    if d.getVar('BB_NO_NETWORK', True) == "1":
        return

    pkgname = d.expand(d.getVar('PN', False))
    newsrc = d.getVarFlag('URLMAP', pkgname, False)

    if not newsrc:
        newsrc = d.getVar('URLMAP', True)

    if not newsrc:
        return

    alluri = d.getVar('SRC_URI', True)
    newuri = ""
    for srcuri in alluri.split():
        scheme, network, path, user, passwd, param = bb.fetch.decodeurl(srcuri)


        # If there is no network defined, check all FILESPATH for the existence
        # of PATH.  If the PATH is found, add it to newuri.
        if not network:
            if os.path.exists(path):
                    newuri += srcuri + " "
                    continue
            added = 0
            for directory in d.getVar('FILESPATH', True).split(':'):
                if os.path.exists(directory + "/" + path):
                    # If the path exists and we're not fetching over the network,
                    # use the local copy.
                    newuri += srcuri + " "
                    added = 1
                    break
            if added:
                continue

        # Drop hard-coded protocol from param if it exists (like protocol=file)
        if "protocol" in param and param["protocol"] == "file":
            del param["protocol"]

        # Remove everything but the last directory name from the path
        dirs = path.split("/")
        repo = "/" + dirs[-1]

        if (repo.endswith(".git")):
           repo = repo[:-4]

        scheme, network, path, user, passwd, newparam = bb.fetch.decodeurl(newsrc)
        path += repo

        # Copy or overwrite any params with the new param values.
        for part in newparam:
            param[part] = newparam[part]

        result = bb.fetch.encodeurl([scheme, network, path, user, passwd, param])
        bb.debug(2, "Changed part of SRC_URI %s to %s for package %s" % (srcuri, result, pkgname))
        newuri += result + " "

    d.setVar("SRC_URI", newuri)
    bb.debug(2, "Changed SRC_URI %s to %s for package %s" % (alluri, newuri, pkgname))
}

