//
// Created by newvi on 01.05.2026.
//

#include "SpyArsenal.h"
#include "EncryptionBox.h"

SpyArsenal::SpyArsenal() : encryptionBox(new EncryptionBox()) {
}

SpyArsenal::~SpyArsenal() {delete encryptionBox;}