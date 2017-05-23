#/bin/bash
cd "$(dirname "$0")"
find ./*/ -name "install_vendors.sh" -type f -execdir ./{} \;