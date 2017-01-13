#! /bin/bash
#
# gen-linux-srcrev: Generate the SRCREV_machine entries for the
#                   linux-windriver recipe
#
#  Copyright (c) 2017 Wind River Systems, Inc.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License version 2 as
#  published by the Free Software Foundation.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#  See the GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

# Run this script from the wr-kernel/git directory.

echo "#"
echo "# This file is generated based on the kernel-4.8.x and kernel-cache repos"
echo "# any manual changes will be overwritten."
echo "#"
echo
echo "OVERRIDES =. \"kb-\${@d.getVar('KBRANCH', True).replace(\"/\", \"-\")}:\""
echo
echo "# kernel-4.8.x branch entries"
(
 if [ -d kernel-4.8.x ]; then
   cd kernel-4.8.x
 elif [ -d kernel-4.8.x.git ]; then
   cd kernel-4.8.x.git
 else
   echo "Unable to find kernel-4.8.x repository." >&2
   exit 1
 fi
 for branch in `git for-each-ref --format='%(refname)' refs/heads` ; do
   echo SRCREV_machine_kb-$(echo $branch | sed 's,refs/heads/,,' | sed 's,/,-,g') ?= \"$(git rev-parse $branch)\"
 done
)

echo
echo "# kernel-cache branch entry"
(
 if [ -d kernel-cache ]; then
   cd kernel-cache
 elif [ -d kernel-cache.git ]; then
   cd kernel-cache.git
 else
   echo "Unable to find kernel-cache repository." >&2
   exit 1
 fi
 echo SRCREV_meta = \"$(git rev-parse WRLINUX_9_0_HEAD)\"
)

