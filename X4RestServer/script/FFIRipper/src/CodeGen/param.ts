
export class Param {

    public name: string;

    public typename: string;

    public constructor(protected paramStr: string) {

    }

    public isPtrType(): boolean {
        return false;
    }

    public isArrayType(): boolean {
        return false;
    }

    public toString(): string {
        return this.paramStr;
    }

}
