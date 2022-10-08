class SnapshotArray {
  constructor(length) {
    this.snapId = 0;
    this.map = new Map();
    this.edit = new Map();
  }

  set(index, val) {
    this.edit.set(index, val);
  }

  snap() {
    this.map.set(this.snapId, this.edit);
    this.edit = new Map();
    return this.snapId++;
  }

  get(index, snap_id) {
    for (let i = snap_id; i >= 0; i--) {
      const currEdit = this.map.get(i);
      if (currEdit.has(index)) return currEdit.get(index);
    }
    return 0;
  }
}
