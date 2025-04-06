/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    if (this.length === 0) {
        return -1;
    }
    const lastIndex = this.length - 1;

    return this[lastIndex]
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */