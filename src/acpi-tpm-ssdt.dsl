/* 
 * SSDT for TPM TIS Interface for Xen with Qemu device model
 * GNU General Public License 
 * Author : Quan Xu <quan.xu@intel.com> 
 */
DefinitionBlock (
    "acpi-tpm-ssdt.aml",
    "SSDT",             
    0x03, 
    "Xen",              
    "vtpm4HVM",         
    0x2                 
    )
{
    Device (TPM) {
        Name (_HID, EisaId ("PNP0C31"))
        Name (_CRS, ResourceTemplate ()
        {
            Memory32Fixed (ReadWrite, 0xFED40000, 0x5000,)
        })
    }

}
