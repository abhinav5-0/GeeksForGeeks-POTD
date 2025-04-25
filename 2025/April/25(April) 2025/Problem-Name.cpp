int count = 0;
        int candidate = -1;

        // Step 1: Find potential candidate
        for (int num : arr) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Step 2: Verify candidate
        count = 0;
        for (int num : arr) {
            if (num == candidate) {
                count++;
            }
        }

        if (count > arr.size() / 2) {
            return candidate;
        } else {
            return -1;
        }
    }
};
