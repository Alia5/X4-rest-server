import { Struct } from './struct';

export class Member {
    public name: string;
    private typeName: string;

    public constructor(protected memberstr: string) {
    }

    public isPtr(): boolean {
        return false;
    }

    public isStruct(): boolean {
        return false;
    }

    public getStruct(): Struct {
        return undefined as Struct;
    }

    public toString(): string {
        return this.memberstr;
    }
}
