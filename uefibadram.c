/*
 * UEFI Bad RAM.
 *
 * A UEFI loader to disable a defective area of RAM before booting into macOS.
 * 
 * Copyright (c) Dan Phillimore (asmblah)
 * https://github.com/asmblah/uefibadram/
 *
 * Released under the MIT license
 * https://github.com/asmblah/uefibadram/raw/main/MIT-LICENSE.txt
 */

#include <uefi.h>

int main (int argc, char **argv)
{
  efi_status_t status;

  efi_physical_address_t startPhysicalAddress = 0x521be0000; // 0x521be02f8, aligned.
  efi_physical_address_t endPhysicalAddress = 0x6aa7ebf70;

  uintn_t numberOfPages = EFI_SIZE_TO_PAGES(endPhysicalAddress - startPhysicalAddress) + 1;

  printf(
    "Marking bad RAM region:\n  Start physical address 0x%x (%dMiB)\n  End physical address 0x%x (%dMiB)\n  (%d x 4KB pages)... ",
    startPhysicalAddress,
    startPhysicalAddress / 1024 / 1024,
    endPhysicalAddress,
    endPhysicalAddress / 1024 / 1024,
    numberOfPages
  );

  status = BS->AllocatePages(AllocateAddress, EfiUnusableMemory, numberOfPages, &startPhysicalAddress);

  if (EFI_ERROR(status)) {
    printf("FAILED: %x\n", status);
  } else {
    printf("Success!\n");
  }

  printf("Finished, press any key to continue...\n");

  getchar();

  printf("Exiting...\n");

  return 0;
}
